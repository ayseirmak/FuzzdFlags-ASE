import random
import re
import subprocess
from pathlib import Path
from datetime import datetime, timedelta

# Parameters
NUM_TEST_PROGRAMS = 1811
DURATION_HOURS = 24
REPEAT_LIMIT = float('inf')   # Number of iterations 50

# Output directory
OUTPUT_DIR = Path("output-nrs")
OUTPUT_DIR.mkdir(exist_ok=True)

# Regex for guards
ASM_RE = re.compile(r'\b(__)?asm\b')
TYPEOF_RE = re.compile(r'\btypeof\b')

def needs_asm(src_text: str) -> bool:
    return bool(ASM_RE.search(src_text))

def needs_typeof(src_text: str) -> bool:
    return bool(TYPEOF_RE.search(src_text))

def read_source(path: Path) -> str:
    return path.read_text(encoding='utf8', errors='ignore')

# Always-used flags
PLUGIN_FLAGS = [
    '-c', '-fpermissive', '-w',
    '-Wno-implicit-function-declaration',
    '-Wno-return-type', '-Wno-builtin-redeclared',
    '-Wno-implicit-int', '-Wno-int-conversion',
    '-march=native', '-I/usr/include',
    '-I/users/user42/llvmSS-include'
]

# Candidate flags
FLAG_LIST = [
    "-O0",
 "-march=x86-64-v3",
 "-march=x86-64-v2",
 "-march=x86-64",
 "-mavx",
 "-mavx2",
 "-mfma", 
 "-mbmi2",    
 "-msha",      
 "-maes",
 "-fno-finite-loops",
 "-fexcess-precision=fast",
 "-fno-use-init-array",
 "-faligned-allocation",
 "-ftrapping-math",
 "-fexcess-precision=standard",
 "-fno-addrsig",
 "-fno-honor-nans",
 "-fno-unroll-loops",
 "-fstrict-return",
 "-fstack-protector-strong",
 "-fno-honor-infinities",
 "-Oz",
 "-Og",
 "-fsigned-zeros",
 "-fno-unsafe-math-optimizations",
 "-funsafe-math-optimizations",
 "-fjump-tables",
 "-O3",
 "-fno-strict-overflow",
 "-fno-associative-math",
 "-ffp-exception-behavior=ignore",
 "-fno-strict-aliasing",
 "-funroll-loops",
 "-ffinite-math-only",
 "-fprotect-parens",
 "-ftls-model=local-exec",
 "-ffp-eval-method=source",
 "-fdenormal-fp-math=positive-zero",
 "-fdenormal-fp-math=preserve-sign",
 "-fno-jump-tables",
 "-femulated-tls",
 "-fstrict-overflow",
 "-ffast-math",
 "-fno-trapping-math",
 "-ffp-exception-behavior=strict",
 "-fno-finite-math-only",
 "-fno-keep-static-consts",
 "-funsigned-bitfields",
 "-ffp-model=precise",
 "-fno-unsigned-char",
 "-ftrapv",
 "-fno-unique-section-names",
 "-fno-signed-char",
 "-flax-vector-conversions",
 "-funique-section-names",
 "-fno-rounding-math",
 "-fassociative-math",
 "-fsignaling-math",
 "-fno-strict-return",
 "-ftls-model=global-dynamic",
 "-fstack-size-section",
 "-fwrapv",
 "-ffp-model=strict",
 "-flax-vector-conversions=integer",
 "-fstack-protector-all",
 "-Os",
 "-fno-math-errno",
 "-fno-approx-func",
 "-fno-protect-parens",
 "-ftls-model=local-dynamic",
 "-fno-fixed-point",
 "-ffp-contract=off",
 "-fno-align-functions",
 "-fstrict-aliasing",
 "-fno-stack-protector",
 "-flax-vector-conversions=none",
 "-falign-functions",
 "-fno-strict-float-cast-overflow",
 "-fvectorize",
 "-faddrsig",
 "-ffp-eval-method=double",
 "-fapprox-func",
 "-ffp-exception-behavior=maytrap",
 "-fhonor-nans",
 "-ftls-model=initial-exec",
 "-ffinite-loops",
 "-fkeep-static-consts",
 "-fstrict-float-cast-overflow",
 "-ffp-contract=fast",
 "-fno-fast-math",
 "-fno-reciprocal-math",
 "-funsigned-char",
 "-frounding-math",
 "-fhonor-infinities",
 "-fdenormal-fp-math=ieee",
 "-ffixed-point",
 "-fno-signaling-math",
 "-fno-lax-vector-conversions",
 "-fno-keep-persistent-storage-variables",
 "-fkeep-persistent-storage-variables",
 "-fstack-protector",
 "-Ofast",
 "-ffp-eval-method=extended",
 "-O2",
 "-ffp-contract=on",
 "-fno-asm",
 "-fno-wrapv",
 "-fno-vectorize",
 "-fsigned-char",
 "-ffunction-sections",
 "-fno-stack-size-section",
 "-fno-signed-zeros",
 "-O1",
 "-funwind-tables",
 "-fsigned-bitfields",
 "-fno-unwind-tables",
 "-fno-function-sections",
 "-freciprocal-math",
 "-fmath-errno",
 "-fno-aligned-allocation",
 "-ffp-model=fast"
]

# Fast bundles/subflags for sanitisation
FAST_BUNDLES = {"-ffast-math", "-Ofast", "-fast"}
FAST_SUBFLAGS = {
    '-fapprox-func', '-fno-approx-func',
    '-freciprocal-math', '-fno-reciprocal-math',
    '-fassociative-math', '-fno-associative-math',
    '-ffp-contract=fast', '-ffp-contract=off',
    '-funsafe-math-optimizations', '-fno-unsafe-math-optimizations'
}

# Generate random subset of flags
def generate_random_flag_subset() -> list[str]:
    bits = [random.choice('01') for _ in FLAG_LIST]
    if '1' not in bits:
        bits[random.randrange(len(bits))] = '1'
    return [flg for flg, b in zip(FLAG_LIST, bits) if b == '1']

# Sanitise candidate flags
def sanitise_flags(raw: list[str], src_text: str) -> list[str]:
    flags = raw.copy()
    # Guard against inline asm
    if needs_asm(src_text):
        flags = [f for f in flags if f not in ('-fno-asm', '-fno-asm-blocks')]
    # Guard fast bundles vs ffp-eval-method
    if any(f in FAST_BUNDLES for f in flags) or any(f in FAST_SUBFLAGS for f in flags):
        flags = [f for f in flags if not f.startswith('-ffp-eval-method=')]
    return flags

# Compile with timeout, return status
def compile_with_flags(src: Path, out_name: str, extra: list[str]) -> str:
    cmd = ["/users/user42/build-clang17/bin/clang", '-x', 'c', str(src), '-o', out_name,
           *PLUGIN_FLAGS, *extra]
    try:
        subprocess.check_output(cmd, stderr=subprocess.STDOUT, timeout=500)
        return 'success'
    except subprocess.TimeoutExpired:
        return 'hang'
    except subprocess.CalledProcessError:
        return 'crash'

# Main fuzz loop
def main():
    crash_count = hang_count = 0
    iterations = 0
    deadline = datetime.now() + timedelta(hours=DURATION_HOURS)

    # Log files
    seed_log = OUTPUT_DIR / 'seeds_log.txt'
    crash_log = OUTPUT_DIR / 'crash_flags.txt'
    hang_log = OUTPUT_DIR / 'hang_flags.txt'
    summary_file = OUTPUT_DIR / 'summary_counters.txt'

    with seed_log.open('w') as log_s, crash_log.open('w') as log_c, hang_log.open('w') as log_h:
        while datetime.now() < deadline and iterations < REPEAT_LIMIT:
            iterations += 1
            src_idx = random.randint(0, NUM_TEST_PROGRAMS - 1)
            src = Path(f"/users/user42/llvmSS-minimised-corpus/test_{src_idx}.c")
            txt = read_source(src)

            # Generate a valid flag set
            while True:
                cand = generate_random_flag_subset()
                san = sanitise_flags(cand, txt)
                if san:
                    flags = san
                    break

            test_id = f"iter{iterations}_src{src_idx}"
            result = compile_with_flags(src, test_id, flags)

            # Prepare log entry
            for flog, outcome in [(log_s, result), (log_c, 'crash'), (log_h, 'hang')]:
                if flog is log_s or result == outcome:
                    flog.write("----------------------------------------\n")
                    flog.write(f"[Checker] Source File: {src}\n")
                    flog.write(f"[Checker] Fixed Flags: {' '.join(PLUGIN_FLAGS)}\n")
                    flog.write(f"[Checker] Flags: {' '.join(flags)}\n")
                    if flog is log_s:
                        flog.write(f"[Checker] Result: {result}\n")

            if result == 'crash':
                crash_count += 1
            elif result == 'hang':
                hang_count += 1

    # Write summary
    summary = (
        f"Total Iterations: {iterations}\n"
        f"Crashes        : {crash_count}\n"
        f"Hangs          : {hang_count}\n"
    )
    summary_file.write_text(summary)
    print(summary)

if __name__ == '__main__':
    main()
