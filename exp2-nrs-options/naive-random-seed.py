import random,re, sys
import subprocess
from pathlib import Path
from datetime import datetime, timedelta

# Parameters
NUM_TEST_PROGRAMS = 1811
DURATION_HOURS = 24
REPEAT_LIMIT = 50 #float('inf')  # Number of iterations or set to a fixed number
OUTPUT_DIR = Path("output-nrs")
OUTPUT_DIR.mkdir(exist_ok=True)

ASM_RE      = re.compile(r'\b(__)?asm\b')
TYPEOF_RE   = re.compile(r'\btypeof\b')

def needs_asm(source_text: str)     -> bool: return bool(ASM_RE.search(source_text))
def needs_typeof(source_text: str)  -> bool: return bool(TYPEOF_RE.search(source_text))

def read_source(path: Path) -> str:
    return path.read_text(encoding='utf8', errors='ignore')

# Base flags that are always included
FAST_BUNDLES = {"-ffast-math", "-Ofast", "-fast"}
FAST_SUBFLAGS = {
    "-fapprox-func", "-fno-approx-func",
    "-freciprocal-math", "-fno-reciprocal-math",
    "-fassociative-math", "-fno-associative-math",
    "-ffp-contract=fast", "-ffp-contract=off",
    "-funsafe-math-optimizations", "-fno-unsafe-math-optimizations"
    # ‘mreassociate’ is implicit; we just keep catching the bundles above
}

PLUGIN_FLAGS = [
    "-c",
    "-fpermissive",
    "-w",
    "-Wno-implicit-function-declaration",
    "-Wno-return-type",
    "-Wno-builtin-redeclared",
    "-Wno-implicit-int",
    "-Wno-int-conversion",
    "-march=native",
    "-I/usr/include",
    "-I/users/user42/llvmSS-include",
    "-lm"
]

# List of additional flags to choose from
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

# ---------- Helper ----------
def generate_random_flag_subset():
    bits = [random.choice("01") for _ in FLAG_LIST]
    if "1" not in bits:
        bits[random.randrange(len(bits))] = "1"
    return [flg for flg, b in zip(FLAG_LIST, bits) if b == "1"]
    
# --- Sanitise flags ---------------------------------------------------------------
def sanitise_flags(raw: list[str], src_text: str) -> list[str]:
    flags = raw.copy()

    # --- Guard 1: asm ----------------------------------------------------------------
    if needs_asm(src_text):
        flags = [f for f in flags if f not in ("-fno-asm", "-fno-asm-blocks")]
    # (Keep -fasm / -fasm-blocks; they don't break inline asm.)

    # --- Guard 2: typeof --------------------------------------------------------------
    #if needs_typeof(src_text):
    #    # inject GNU dialect (only if not already picked)
    #    if not any(f.startswith("-std=") for f in flags):
    #        flags.append("-std=gnu11")

    # --- Guard 3: ffp-eval-method vs fast bundles ------------------------------------
    has_fast     = any(f in FAST_BUNDLES for f in flags)
    has_subfast  = any(f in FAST_SUBFLAGS for f in flags)
    if has_fast or has_subfast:
        flags = [f for f in flags if not f.startswith("-ffp-eval-method=")]

    return flags
    
def compile_with_flags(src, out_name, extra):
    
    cmd = ["/users/user42/build-test/bin/clang", "-x", "c", str(src), "-o", out_name, *PLUGIN_FLAGS, *extra, "-std=gnu11"]
    try:
        subprocess.check_output(cmd, stderr=subprocess.STDOUT,timeout=500)
        return True
    except subprocess.CalledProcessError:
        return False

def run_binary(bin_name, inp):
    try:
        res = subprocess.run(
            ["./" + bin_name], input=inp.encode(),
            stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=10
        )
        return res.returncode, res.stdout.strip()
    except subprocess.TimeoutExpired:
        return -999, b"__TIMEOUT__"
    except Exception:
        return -998, b"__ERROR__"

# ---------- Main ----------
def main():
    ok = compile_failed = 0
    diff_both = diff_rc = diff_out = 0
    iterations = 0
    deadline = datetime.now() + timedelta(hours=DURATION_HOURS)

    # Prepare log files in output directory
    log_random = OUTPUT_DIR / "randomization_log.txt"
    log_compile = OUTPUT_DIR / "compile_failure_flags.txt"
    log_diff_both = OUTPUT_DIR / "diff_both_flags.txt"
    log_diff_rc = OUTPUT_DIR / "diff_rc_flags.txt"
    log_diff_out = OUTPUT_DIR / "diff_out_flags.txt"
    summary_file = OUTPUT_DIR / "summary_counters.txt"

    with log_random.open("w") as qf:
        qf.write("Processing naive randomization script'...\n")

        while datetime.now() < deadline and iterations < REPEAT_LIMIT:
            
            for b in ("bin1", "bin2"):
                try:
                    Path(b).unlink()
                except FileNotFoundError:
                    pass

            iterations += 1
            src_idx = random.randint(0, NUM_TEST_PROGRAMS-1)
            src     = Path(f"/users/user42/llvmSS-minimised-corpus/test_{src_idx}.c")
            txt     = read_source(src)
            input_data = str(1000000)

            flag_pairs = []
            success = True
            for tag in ("bin1", "bin2"):
                flags_v1 = generate_random_flag_subset()
                flags = sanitise_flags(flags_v1, txt)
                flag_pairs.append(flags)
                if not compile_with_flags(src, tag, flags):
                    compile_failed += 1
                    with log_compile.open("a") as flog:
                        flog.write("----------------------------------------\n")
                        flog.write(f"[Checker] Source File: {src}\n")
                        flog.write(f"[Checker] Fixed Flags: -c {' '.join(PLUGIN_FLAGS)}\n")
                        flog.write(f"[Checker] Flags: {' '.join(flags)}\n")
                    success = False
                    break

            if not success:
                continue

            for flags in flag_pairs:
                flags = flags + ["-std=gnu11"]
                qf.write("----------------------------------------\n")
                qf.write(f"[Checker] Source File: {src}\n")
                qf.write(f"[Checker] Fixed Flags: -c {' '.join(PLUGIN_FLAGS)}\n")
                qf.write(f"[Checker] Flags: {' '.join(flags)}\n")

            # rc1, out1 = run_binary("bin1", input_data)
            # rc2, out2 = run_binary("bin2", input_data)

            # if rc1 == rc2 and out1 == out2:
            #     ok += 1

            # elif rc1 != rc2 and out1 != out2:
            #     diff_both += 1
            #     with log_diff_both.open("a") as flog:
            #         for flags in flag_pairs:
            #             flags_log = flags + ["-std=gnu11"]
            #             flog.write("----------------------------------------\n")
            #             flog.write(f"[Checker] Source File: {src}\n")
            #             flog.write(f"[Checker] Fixed Flags: -c {' '.join(PLUGIN_FLAGS)}\n")
            #             flog.write(f"[Checker] Flags: {' '.join(flags_log)}\n")

            # elif rc1 != rc2:
            #     diff_rc += 1
            #     with log_diff_rc.open("a") as flog:
            #         for flags in flag_pairs:
            #             flags_log = flags + ["-std=gnu11"]
            #             flog.write("----------------------------------------\n")
            #             flog.write(f"[Checker] Source File: {src}\n")
            #             flog.write(f"[Checker] Fixed Flags: -c {' '.join(PLUGIN_FLAGS)}\n")
            #             flog.write(f"[Checker] Flags: {' '.join(flags_log)}\n")

            # else:  # rc1 == rc2 but out1 != out2
            #     diff_out += 1
            #     with log_diff_out.open("a") as flog:
            #         for flags in flag_pairs:
            #             flags_log = flags + ["-std=gnu11"]
            #             flog.write("----------------------------------------\n")
            #             flog.write(f"[Checker] Source File: {src}\n")
            #             flog.write(f"[Checker] Fixed Flags: -c {' '.join(PLUGIN_FLAGS)}\n")
            #             flog.write(f"[Checker] Flags: {' '.join(flags_log)}\n")

    summary = (
        "Summary:\n"
        f"  OK                : {ok}\n"
        f"  COMPILATION FAILED: {compile_failed}\n"
        f"  DIFF_BOTH (rc+out): {diff_both}\n"
        f"  DIFF_RC           : {diff_rc}\n"
        f"  DIFF_OUTPUT       : {diff_out}\n"
        f"  TOTAL RUNS        : {iterations}\n"
    )
    print("\n" + summary)
    summary_file.write_text(summary)

if __name__ == "__main__":
    main()
