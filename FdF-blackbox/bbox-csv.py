import hashlib
import random
import re
import shutil
import subprocess
import tempfile
from pathlib import Path
import csv
from datetime import datetime, timedelta


# ===========================
# CONFIG — edit these paths
# ===========================
CLANG       = Path("/opt/llvm-latest/bin/clang")
CORPUS_DIR  = Path("/users/a_irmak/programs2")
MUTATOR_DIR = Path("/users/a_irmak/mutators/build")
OUTPUT_DIR  = Path("output-bbox2")
LOG_CSV     = OUTPUT_DIR / "iter_log.csv"

# Standalone mutators (only those that exist will be used)
MUTATORS = [
    ("constant",   MUTATOR_DIR / "constant-mutator"),
    ("delete",     MUTATOR_DIR / "delete-mutator"),
    ("duplicate",  MUTATOR_DIR / "duplicate-mutator"),
    ("expression", MUTATOR_DIR / "expression-mutator"),
    ("jump",       MUTATOR_DIR / "jump-mutator"),
]
MUTATORS = [(n, p) for (n, p) in MUTATORS if p.exists()]

# Campaign parameters
DURATION_HOURS = 72  # total duration
REPEAT_LIMIT = float('inf')
# REPEAT_LIMIT = 15

P_MUTATE            = 0.90   # 90% mutate+compile, 10% flags-only
MAX_FLAGS_PER_RUN   = 10     # <= 10 flags total

# Always-used flags for compilation
PLUGIN_FLAGS = [
    '-c', '-fpermissive', '-w',
    '-Wno-implicit-function-declaration', '-Wno-return-type',
    '-Wno-builtin-redeclared', '-Wno-implicit-int', '-Wno-int-conversion',
    '-march=native', '-I/usr/include', '-I/users/a_irmak/llvmSS-include', '-o', '/dev/null'
]

# Minimal flags for libTooling parsing (passed after `--` to mutators)
TOOLING_FLAGS = [
    '-x', 'c', '-std=c11', '-I/usr/include',
    '-include', 'stdlib.h', '-include', 'stdio.h',
    '-I/users/a_irmak/llvmSS-include'
]

# Candidate flags (your original list)
FLAG_LIST = [
    "-O0","-march=x86-64-v3","-march=x86-64-v2","-march=x86-64","-mavx","-mavx2",
    "-mfma","-mbmi2","-msha","-maes","-fno-finite-loops","-fexcess-precision=fast",
    "-fno-use-init-array","-faligned-allocation","-ftrapping-math",
    "-fexcess-precision=standard","-fno-addrsig","-fno-honor-nans","-fno-unroll-loops",
    "-fstrict-return","-fstack-protector-strong","-fno-honor-infinities","-Oz","-Og",
    "-fsigned-zeros","-fno-unsafe-math-optimizations","-funsafe-math-optimizations",
    "-fjump-tables","-O3","-fno-strict-overflow","-fno-associative-math",
    "-ffp-exception-behavior=ignore","-fno-strict-aliasing","-funroll-loops",
    "-ffinite-math-only","-fprotect-parens","-ftls-model=local-exec","-ffp-eval-method=source",
    "-fdenormal-fp-math=positive-zero","-fdenormal-fp-math=preserve-sign",
    "-fno-jump-tables","-femulated-tls","-fstrict-overflow","-ffast-math","-fno-trapping-math",
    "-ffp-exception-behavior=strict","-fno-finite-math-only","-fno-keep-static-consts",
    "-funsigned-bitfields","-ffp-model=precise","-fno-unsigned-char","-ftrapv",
    "-fno-unique-section-names","-fno-signed-char","-flax-vector-conversions",
    "-funique-section-names","-fno-rounding-math","-fassociative-math","-fsignaling-math",
    "-fno-strict-return","-ftls-model=global-dynamic","-fstack-size-section","-fwrapv",
    "-ffp-model=strict","-flax-vector-conversions=integer","-fstack-protector-all","-Os",
    "-fno-math-errno","-fno-approx-func","-fno-protect-parens","-ftls-model=local-dynamic",
    "-fno-fixed-point","-ffp-contract=off","-fno-align-functions","-fstrict-aliasing",
    "-fno-stack-protector","-flax-vector-conversions=none","-falign-functions",
    "-fno-strict-float-cast-overflow","-fvectorize","-faddrsig","-ffp-eval-method=double",
    "-fapprox-func","-ffp-exception-behavior=maytrap","-fhonor-nans","-ftls-model=initial-exec",
    "-ffinite-loops","-fkeep-static-consts","-fstrict-float-cast-overflow","-ffp-contract=fast",
    "-fno-fast-math","-fno-reciprocal-math","-funsigned-char","-frounding-math","-fhonor-infinities",
    "-fdenormal-fp-math=ieee","-ffixed-point","-fno-signaling-math","-fno-lax-vector-conversions",
    "-fno-keep-persistent-storage-variables","-fkeep-persistent-storage-variables","-fstack-protector",
    "-Ofast","-ffp-eval-method=extended","-O2","-ffp-contract=on","-fno-asm","-fno-wrapv","-fno-vectorize",
    "-fsigned-char","-ffunction-sections","-fno-stack-size-section","-fno-signed-zeros","-O1","-funwind-tables",
    "-fsigned-bitfields","-fno-unwind-tables","-fno-function-sections","-freciprocal-math","-fmath-errno",
    "-fno-aligned-allocation","-ffp-model=fast"
]

# Helpers & guards
ASM_RE = re.compile(r'\b(__)?asm\b')

FAST_BUNDLES = {"-ffast-math", "-Ofast", "-fast"}
FAST_SUBFLAGS = {
    '-fapprox-func','-fno-approx-func','-freciprocal-math','-fno-reciprocal-math',
    '-fassociative-math','-fno-associative-math','-ffp-contract=fast','-ffp-contract=off',
    '-funsafe-math-optimizations','-fno-unsafe-math-optimizations'
}

def read_source(path: Path) -> str:
    try:
        return path.read_text(encoding='utf8', errors='ignore')
    except Exception:
        return "cant read source"

def sanitise_flags(raw: list[str], src_text: str) -> list[str]:
    flags = list(raw)
    # Don't forbid inline asm if the source actually uses it.
    if ASM_RE.search(src_text):
        flags = [f for f in flags if f not in ('-fno-asm', '-fno-asm-blocks')]
    # If fast-math or related subflags appear, drop -ffp-eval-method=*
    if any(f in FAST_BUNDLES for f in flags) or any(f in FAST_SUBFLAGS for f in flags):
        flags = [f for f in flags if not f.startswith('-ffp-eval-method=')]
    return flags

def choose_flags(src_text: str) -> list[str]:
    while True:
        k = random.randint(1, min(MAX_FLAGS_PER_RUN, len(FLAG_LIST)))
        candidate = random.sample(FLAG_LIST, k)  # distinct flags
        flags = sanitise_flags(candidate, src_text)
        if flags:
            return flags

def compile_with_flags(src: Path, extra: list[str]) -> str:
    cmd = [str(CLANG), '-x', 'c', str(src), *PLUGIN_FLAGS, *extra]
    try:
        subprocess.check_output(cmd, stderr=subprocess.STDOUT, timeout=500)
        return 'success'
    except subprocess.TimeoutExpired:
        return 'hang'
    except subprocess.CalledProcessError:
        return 'crash'

def fast_hash(path: Path) -> str:
    h = hashlib.blake2b(digest_size=16)  # 128-bit fingerprint is plenty
    with path.open('rb') as f:
        for chunk in iter(lambda: f.read(8192), b''):
            h.update(chunk)
    return h.hexdigest()

def is_real_mutation(original: Path, candidate: Path) -> bool:
    try:
        if original.stat().st_size != candidate.stat().st_size:
            return True
        return fast_hash(original) != fast_hash(candidate)
    except FileNotFoundError:
        return False

def run_mutator(name: str, exe: Path, src: Path, seed: int) -> Path | None:
    """
    Run a single mutator. Returns <base>.mutated.c if created.
    Execute in the source's directory and pass only the basename so GrayC
    writes the output next to that file (i.e., inside the temp workspace).
    """
    out = src.with_suffix(".mutated.c")
    try:
        if out.exists():
            out.unlink()
    except Exception:
        print("Failed to unlink mutated file")
    cmd = [str(exe), src.name, '--', *TOOLING_FLAGS, str(seed)]
    try:
        subprocess.check_output(cmd, stderr=subprocess.STDOUT, timeout=120, cwd=str(src.parent))
        return out if out.exists() else None
    except (subprocess.CalledProcessError, subprocess.TimeoutExpired):
        return None

def unique_name(dst_dir: Path, base: str, ext: str = ".c") -> Path:
    p = dst_dir / f"{base}{ext}"
    if not p.exists():
        return p
    n = 1
    while True:
        q = dst_dir / f"{base}.{n}{ext}"
        if not q.exists():
            return q
        n += 1

def main():
    OUTPUT_DIR.mkdir(exist_ok=True)
    it = 0
    corpus = sorted(CORPUS_DIR.glob("*.c"))
    if not corpus:
        raise SystemExit(f"No .c files in {CORPUS_DIR}")
    
    deadline = datetime.now() + timedelta(hours=DURATION_HOURS)

    seen_hashes = {fast_hash(p) for p in corpus}
    crash_count = hang_count = added_count = 0

    # open CSV log
    LOG_CSV.parent.mkdir(exist_ok=True)
    with LOG_CSV.open('w', newline='') as logf:
        writer = csv.writer(logf)
        writer.writerow([
            "iter","src","mutator","seed","mutation_status",
            "mutated_program","flags_count","flags",
            "compilation_outcome","res_hash"
        ])

        while datetime.now() < deadline and it < REPEAT_LIMIT:
            it += 1
            src = random.choice(corpus)
            src_text = read_source(src)
            flags = choose_flags(src_text)
            flags_str = " ".join(flags)

            # default per-iter fields
            attempted_mut = False
            mutator_name = "-"
            mut_seed = "-"
            mutation_status = "skipped"   # will update below
            mutated_program_path = str(src)  # default to source
            res_hash = ""
            result = "success"

            with tempfile.TemporaryDirectory(prefix="bbox_") as tmpdir_str:
                tmpdir = Path(tmpdir_str)
                work_src = tmpdir / src.name
                shutil.copy2(src, work_src)
                compile_src = work_src

                mutated_distinct = False
                out_path: Path | None = None

                # Optional mutation attempt
                if MUTATORS and random.random() < P_MUTATE:
                    attempted_mut = True
                    mutator_name, exe = random.choice(MUTATORS)
                    mut_seed = str(random.randrange(1, 2**31 - 1))
                    out_path = run_mutator(mutator_name, exe, work_src, int(mut_seed))
                    print('[*]source:', work_src)
                    print('[*]mut-out:', out_path)
                    if out_path is None:
                        mutation_status = "failed"   # mutator crashed or timed out
                    else:
                        if is_real_mutation(work_src, out_path):
                            compile_src = out_path
                            mutated_distinct = True
                        else:
                            mutation_status = "no-op"

                # Compile (either source or mutated temp file)
                result = compile_with_flags(compile_src, flags)
                res_hash = fast_hash(compile_src)

                # Decide promotion and final mutation_status / mutated_program
                if not attempted_mut:
                    mutation_status = "skipped"
                    mutated_program_path = str(src)
                else:
                    if out_path is None:
                        # already "failed"
                        mutated_program_path = str(src)
                    elif not mutated_distinct:
                        # already "no-op"
                        mutated_program_path = str(src)
                    else:
                        # success + distinct content: promote only if new
                        if res_hash not in seen_hashes:
                            dest = unique_name(CORPUS_DIR, f"{src.stem}_{res_hash[:8]}", ".c")
                            shutil.copy2(compile_src, dest)
                            seen_hashes.add(res_hash)
                            corpus.append(dest)
                            added_count += 1
                            mutation_status = "applied"
                            mutated_program_path = str(dest)
                        else:
                            mutation_status = "duplicate"
                            mutated_program_path = str(src)

            if result == 'crash':
                crash_count += 1
            elif result == 'hang':
                hang_count += 1

            # console line
            print(f"[{it:03}] {result:7s}  flags={len(flags):2d}  "
                  f"mut={mutator_name}:{mut_seed:<10} status={mutation_status:<7}  "
                  f"mut_prog={'src' if mutated_program_path==str(src) else 'new'}  corpus={len(corpus)}")
            print('---------------------------------------------------------------------------------------')

            # CSV row
            writer.writerow([
                it, str(src), mutator_name, mut_seed, mutation_status,
                mutated_program_path, len(flags), flags_str, result, res_hash
            ])
            logf.flush()

    print("\n=== Summary ===")
    print(f"Total iterations : {it}")
    print(f"Crashes          : {crash_count}")
    print(f"Hangs            : {hang_count}")
    print(f"New corpus files : {added_count}")
    print(f"Corpus size      : {len(corpus)}")

if __name__ == '__main__':
    main()