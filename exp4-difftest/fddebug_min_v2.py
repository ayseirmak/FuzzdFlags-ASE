#!/usr/bin/env python3
import sys, subprocess, os, json

# Usage (both supported):
#   fddebug_min_v2.py <test_no> <RC17> <RC19> <RC22> <flags...>
#   fddebug_min_v2.py <clang_path|17|19|22> <test_no> <RC17> <RC19> <RC22> <flags...>
# Grows the ordered flag prefix until the cross-version RC triple (17,19,22) matches.

BASE_DIR = "/users/user42"
CORPUS_DIR = f"{BASE_DIR}/llvmSS-minimised-corpus"
INCLUDES_DIR = f"{BASE_DIR}/llvmSS-include"
COMP17 = f"{BASE_DIR}/build/bin/clang-17"
COMP19 = f"{BASE_DIR}/llvm-19-build/bin/clang-19"
COMP22 = f"{BASE_DIR}/llvm-latest-build/bin/clang-22"
COMPILE_TIMEOUT = 60
EXEC_TIMEOUT = 30

CONSTANT_FLAGS = [
    "-std=gnu89", "-fpermissive", "-w",
    "-Wno-implicit-function-declaration", "-Wno-implicit-int",
    "-Wno-return-type", "-Wno-builtin-declaration-mismatch", "-Wno-int-conversion",
    "-march=native", "-I/usr/include", "-lm", f"-I{INCLUDES_DIR}"
]

def dedupe_keep_last_order(raw_flags):
    seen = set(); out = []
    for f in raw_flags:
        if f in seen:
            out.remove(f)
        else:
            seen.add(f)
        out.append(f)
    return out

def compile_with_flags(clang, flags, test_file, exe):
    if os.path.exists(exe):
        os.remove(exe)
    cmd = ["timeout", str(COMPILE_TIMEOUT), clang] + CONSTANT_FLAGS + flags + [test_file, "-o", exe]
    cp = subprocess.run(cmd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return cp.returncode

def run_binary(exe):
    rp = subprocess.run(["timeout", str(EXEC_TIMEOUT), exe],
                        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return rp.returncode

def effective_rc(clang, flags, test_file, tag):
    exe = f"./_tmp_{tag}.exe"
    c_rc = compile_with_flags(clang, flags, test_file, exe)
    try:
        if c_rc != 0:
            return ("compile", c_rc)
        r_rc = run_binary(exe)
        return ("exec", r_rc)
    finally:
        if os.path.exists(exe):
            os.remove(exe)

def parse_expected(tok):
    tok = tok.strip()
    if tok in ("*", "x", "?"):
        return None
    return int(tok)

def match_triple(got, want):
    for g, w in zip(got, want):
        if w is None:  # wildcard
            continue
        if g != w:
            return False
    return True

def main():
    if len(sys.argv) < 5:
        print("Usage:\n  fddebug_min_v2.py <test_no> <RC17> <RC19> <RC22> <flags...>\n  fddebug_min_v2.py <clang|17|19|22> <test_no> <RC17> <RC19> <RC22> <flags...>")
        sys.exit(1)

    # Flexible CLI parsing: detect whether first arg is test_no (digits) or a clang arg.
    arg1 = sys.argv[1]
    use_short = arg1.isdigit()

    if use_short:
        test_no = sys.argv[1]
        exp17 = parse_expected(sys.argv[2])
        exp19 = parse_expected(sys.argv[3])
        exp22 = parse_expected(sys.argv[4])
        raw_flags = sys.argv[5:]
    else:
        # legacy/long form; clang_arg accepted but not needed (we always test 17/19/22)
        # still parse it for compatibility
        clang_arg = sys.argv[1]
        test_no = sys.argv[2]
        exp17 = parse_expected(sys.argv[3])
        exp19 = parse_expected(sys.argv[4])
        exp22 = parse_expected(sys.argv[5])
        raw_flags = sys.argv[6:]

    test_file = os.path.join(CORPUS_DIR, f"test_{test_no}.c")
    if not os.path.exists(test_file):
        print(json.dumps({"error": f"missing test file: {test_file}"}))
        sys.exit(2)

    flags = dedupe_keep_last_order(raw_flags)
    want = [exp17, exp19, exp22]

    found = None
    details = None

    # Grow prefix: 1..len(flags)
    for i in range(1, len(flags) + 1):
        prefix = flags[:i]
        st17, rc17 = effective_rc(COMP17, prefix, test_file, f"17_{i}")
        st19, rc19 = effective_rc(COMP19, prefix, test_file, f"19_{i}")
        st22, rc22 = effective_rc(COMP22, prefix, test_file, f"22_{i}")
        got = [rc17, rc19, rc22]

        if match_triple(got, want):
            found = prefix
            details = {
                "stages": {"17": st17, "19": st19, "22": st22},
                "rcs": {"17": rc17, "19": rc19, "22": rc22},
                "prefix_len": i
            }
            break

    out = {
        "test": test_no,
        "expected": {"17": exp17, "19": exp19, "22": exp22},
        "strategy": "prefix-grow-cross-version",
        "deduped_flags": flags,
        "match_found": bool(found),
        "min_matching_prefix": (found or []),
        "details": details
    }
    print(json.dumps(out, indent=2))

if __name__ == "__main__":
    main()
