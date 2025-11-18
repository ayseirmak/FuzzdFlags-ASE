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
CLANG_LATEST = Path("/opt/llvm-latest/bin/clang")
CLANG_17     = Path("/opt/llvm-17/bin/clang")
CLANG_19     = Path("/opt/llvm-19/bin/clang")

# Alias used by the main per-iteration verdict (unchanged logic)
CLANG = CLANG_17

CORPUS_DIR  = Path("/users/a_irmak/programs")
MUTATOR_DIR = Path("/users/a_irmak/mutators/build")
OUTPUT_DIR  = Path("output-bbox")
LOG_CSV     = OUTPUT_DIR / "iter_log.csv"
DIFF_CSV    = OUTPUT_DIR / "diff_test.csv"   # NEW
RUN_TIMEOUT_S = 10

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
DURATION_HOURS = 72
REPEAT_LIMIT = float('inf')
# REPEAT_LIMIT = 60

P_MUTATE            = 0.90
MAX_FLAGS_PER_RUN   = 10

# Always-used flags for compilation
PLUGIN_FLAGS = [
    '-c', '-fpermissive', '-w',
    '-Wno-implicit-function-declaration', '-Wno-return-type',
    '-Wno-builtin-redeclared', '-Wno-implicit-int', '-Wno-int-conversion',
    '-march=native', '-I/usr/include', '-I/users/a_irmak/llvmSS-include', '-o', '/dev/null'
]

# Minimal flags for libTooling parsing (passed after `--` to mutators)
TOOLING_FLAGS = [
    '-x', 'c', '-w',
    '-Wno-implicit-function-declaration', '-Wno-return-type',
    '-Wno-builtin-redeclared', '-Wno-implicit-int', '-Wno-int-conversion',
    '-march=native', '-I/usr/include', '-include', 'stdlib.h', '-include', 'stdio.h',
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
    if ASM_RE.search(src_text):
        flags = [f for f in flags if f not in ('-fno-asm', '-fno-asm-blocks')]
    if any(f in FAST_BUNDLES for f in flags) or any(f in FAST_SUBFLAGS for f in flags):
        flags = [f for f in flags if not f.startswith('-ffp-eval-method=')]
    return flags

def choose_flags(src_text: str) -> list[str]:
    while True:
        k = random.randint(1, min(MAX_FLAGS_PER_RUN, len(FLAG_LIST)))
        candidate = random.sample(FLAG_LIST, k)
        flags = sanitise_flags(candidate, src_text)
        if flags:
            return flags

def _strip_c_and_o(flags: list[str]) -> list[str]:
    out: list[str] = []
    skip_next = False
    for tok in flags:
        if skip_next:
            skip_next = False
            continue
        if tok == '-c':
            continue
        if tok == '-o':
            skip_next = True  # skip output path that follows
            continue
        out.append(tok)
    return out

# --- helpers for difftest ---
def hash_bytes(data: bytes) -> str:
    h = hashlib.blake2b(digest_size=16)
    h.update(data or b'')
    return h.hexdigest()

def compile_capture(compiler: Path, src: Path, extra: list[str], timeout_s: int = 500):
    cmd = [str(compiler), '-x', 'c', str(src), *PLUGIN_FLAGS, *extra]
    try:
        p = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=timeout_s)
        out = p.stdout or b''
        rc = p.returncode
        # (2) classify non-zero rc: negative rc => crash (killed by signal), positive => build-fail
        if rc == 0:
            status = 'success'
        elif isinstance(rc, int) and (rc > 128 or rc < 0):
            status = 'crash'
        else:
            status = 'build-fail'
        return status, rc, out
    except subprocess.TimeoutExpired as e:
        out = (getattr(e, 'output', None) or b'') + (getattr(e, 'stdout', None) or b'')
        return 'hang', 'TIMEOUT', out
    except FileNotFoundError:
        return 'missing', 'MISSING', b''
    except Exception as ex:
        return 'error', f'ERROR:{type(ex).__name__}', str(ex).encode('utf-8', errors='ignore')

def compile_with_flags(src: Path, extra: list[str]) -> str:
    status, _, _ = compile_capture(CLANG, src, extra)
    return status

def build_and_run_capture(compiler: Path, src: Path, extra: list[str],
                          run_timeout_s: int = RUN_TIMEOUT_S):
    """
    Build (compile+link) the program and then run it.
    Return: (status, rc, out_bytes)
      - status: 'ok' if program ran, 'build-fail', 'hang', 'missing', or 'error'
      - rc    : int exit code, or 'CFAIL:<code>', 'TIMEOUT', 'MISSING', 'ERROR:<...>'
      - out   : bytes of stdout+stderr (from run on success; from compiler on build-fail)
    """
    if not compiler.exists():
        return 'missing', 'MISSING', b''

    link_flags = _strip_c_and_o(PLUGIN_FLAGS)

    # Build executable in a private temp dir
    with tempfile.TemporaryDirectory(prefix="bbox_exec_") as exedir:
        exe = Path(exedir) / "a.out"
        cmd = [str(compiler), '-x', 'c', str(src), *link_flags, *extra, '-lm', '-o', str(exe)]
        try:
            build = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=500)
        except subprocess.TimeoutExpired as e:
            out = (getattr(e, 'output', None) or b'') + (getattr(e, 'stdout', None) or b'')
            return 'hang', 'TIMEOUT', out
        except Exception as ex:
            return 'error', f'ERROR:{type(ex).__name__}', str(ex).encode('utf-8', errors='ignore')

        if build.returncode != 0:
            return 'build-fail', f'CFAIL:{build.returncode}', (build.stdout or b'')

        # Build succeeded → run the program
        try:
            runp = subprocess.run([str(exe)], stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                  timeout=run_timeout_s, input=None)
            return 'ok', runp.returncode, (runp.stdout or b'')
        except subprocess.TimeoutExpired as e:
            out = (getattr(e, 'output', None) or b'') + (getattr(e, 'stdout', None) or b'')
            return 'hang', 'TIMEOUT', out
        except Exception as ex:
            return 'error', f'ERROR:{type(ex).__name__}', str(ex).encode('utf-8', errors='ignore')


def fast_hash(path: Path) -> str:
    h = hashlib.blake2b(digest_size=16)
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

def perform_and_maybe_log_difftest(src_in_tmp: Path, final_prog_path_str: str, flags: list[str], diff_writer) -> bool:
    """Run difftest for {latest, 17, 19} every iteration, building+linking (-lm) and running the program."""
    compilers = [('l', CLANG_LATEST), ('17', CLANG_17), ('19', CLANG_19)]
    results = {}  # tag -> {'status', 'rc', 'out_hash'}

    for tag, comp in compilers:
        status, rc, out = build_and_run_capture(comp, src_in_tmp, flags)
        if status == 'missing':
            results[tag] = {'status': 'missing', 'rc': 'MISSING', 'out_hash': 'NA'}
        elif status == 'ok':
            # (1) only hash output when the run succeeded
            results[tag] = {'status': 'ok', 'rc': str(rc), 'out_hash': hash_bytes(out)}
        else:
            # build-fail / hang / error: keep rc string; do not hash compiler/partial output
            results[tag] = {'status': status, 'rc': str(rc), 'out_hash': 'NA'}

    # Extract fields with safe defaults for CSV (schema unchanged)
    rc_l  = results.get('l',  {}).get('rc', 'MISSING')
    rc_17 = results.get('17', {}).get('rc', 'MISSING')
    rc_19 = results.get('19', {}).get('rc', 'MISSING')
    oh_l  = results.get('l',  {}).get('out_hash', 'NA')
    oh_17 = results.get('17', {}).get('out_hash', 'NA')
    oh_19 = results.get('19', {}).get('out_hash', 'NA')

    # --- Diff policy ---
    # RC differences among toolchains that actually ran (i.e., not 'missing').
    present = [r for r in results.values() if r['status'] != 'missing']
    rc_vals = [r['rc'] for r in present]
    rc_diff = (len(set(rc_vals)) > 1)

    # (3) Compare program outputs ONLY if all present toolchains succeeded.
    all_ok  = (present and all(r['status'] == 'ok' for r in present))
    out_diff = False
    if all_ok:
        outs = [r['out_hash'] for r in present]
        out_diff = (len(set(outs)) > 1)

    differs = rc_diff or out_diff

    if differs:
        flags_str = " ".join(flags)
        diff_writer.writerow([
            final_prog_path_str, flags_str,
            rc_l, rc_17, rc_19,
            oh_l, oh_17, oh_19
        ])
        return True
    return False


def main():
    OUTPUT_DIR.mkdir(exist_ok=True)
    it = 0
    corpus = sorted(CORPUS_DIR.glob("*.c"))
    if not corpus:
        raise SystemExit(f"No .c files in {CORPUS_DIR}")
    
    deadline = datetime.now() + timedelta(hours=DURATION_HOURS)

    seen_hashes = {fast_hash(p) for p in corpus}
    crash_count = build_fail_count = hang_count = added_count = diff_count = 0

    LOG_CSV.parent.mkdir(exist_ok=True)

    # diff csv opened in append mode; write header if file didn't exist
    diff_file_existed = DIFF_CSV.exists()
    difff = DIFF_CSV.open('a', newline='')
    diff_writer = csv.writer(difff)
    if not diff_file_existed:
        diff_writer.writerow([
            "program_path","flags",
            "rc-l","rc-17","rc-19",
            "out-l-hash","out-17-hash","out-19-hash"
        ])

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

            attempted_mut = False
            mutator_name = "-"
            mut_seed = "-"
            mutation_status = "skipped"
            mutated_program_path = str(src)
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

                # Compile with clang-latest for the iteration verdict
                result = compile_with_flags(compile_src, flags)
                res_hash = fast_hash(compile_src)

                # Promotion policy: keep yours (promote distinct mutants, regardless of baseline compile result)
                if not attempted_mut:
                    mutation_status = "skipped"
                    mutated_program_path = str(src)
                else:
                    if out_path is None:
                        mutated_program_path = str(src)
                    elif not mutated_distinct:
                        mutated_program_path = str(src)
                    else:
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

                # Differential testing — run on EVERY iteration
                logged = perform_and_maybe_log_difftest(compile_src, mutated_program_path, flags, diff_writer)
                if logged:
                    diff_count += 1
                    print("    [DIFF] divergence recorded in diff_test.csv")

            # scoreboard counters
            if result == 'crash':
                crash_count += 1
            elif result == 'build-fail':
                build_fail_count += 1
            elif result == 'hang':
                hang_count += 1

            # console line
            print(f"[{it:03}] {result:11s} flags={len(flags):2d}  "
                  f"mut={mutator_name}:{mut_seed:<10} status={mutation_status:<12}  "
                  f"mut_prog={'src' if mutated_program_path==str(src) else 'new'}  corpus={len(corpus)}")
            print('---------------------------------------------------------------------------------------')

            # CSV row
            writer.writerow([
                it, str(src), mutator_name, mut_seed, mutation_status,
                mutated_program_path, len(flags), flags_str, result, res_hash
            ])
            logf.flush()
            difff.flush()

    difff.close()
    print("\n=== Summary ===")
    print(f"Total iterations : {it}")
    print(f"Crashes          : {crash_count}")
    print(f"Build-fails      : {build_fail_count}")
    print(f"Hangs            : {hang_count}")
    print(f"New corpus files : {added_count}")
    print(f"Difftest diffs   : {diff_count}")
    print(f"Corpus size      : {len(corpus)}")

if __name__ == '__main__':
    main()
