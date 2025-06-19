import random
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

# Always-used flags (plugin flags)
PLUGIN_FLAGS = [
    '-c', '-fpermissive', '-w',
    '-Wno-implicit-function-declaration',
    '-Wno-return-type', '-Wno-builtin-redeclared',
    '-Wno-implicit-int', '-Wno-int-conversion',
    '-march=native', '-I/usr/include',
    '-I/users/user42/llvmSS-include', '-lm'
]

# Candidate flags list
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

# Generate random non-empty subset of flags
def generate_random_flag_subset() -> list[str]:
    bits = [random.choice('01') for _ in FLAG_LIST]
    if '1' not in bits:
        bits[random.randrange(len(bits))] = '1'
    return [flg for flg, b in zip(FLAG_LIST, bits) if b == '1']

# Compile with timeout, return status
def compile_with_flags(src: Path, out_name: str, flags: list[str]) -> str:
    cmd = ["/users/user42/build-clang17/bin/clang", '-x', 'c', str(src), '-o', out_name,
           *PLUGIN_FLAGS, *flags]
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

            # Generate a random flag set
            flags = generate_random_flag_subset()

            test_id = f"iter{iterations}_src{src_idx}"
            result = compile_with_flags(src, test_id, flags)

            # Log entry for seed and outcome
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
