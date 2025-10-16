#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>

// LLVM/Clang
#include "clang/Basic/Version.h"
#include "clang/Driver/Driver.h"
#include "clang/Driver/Compilation.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "llvm/TargetParser/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Option/Option.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Support/VirtualFileSystem.h"

// -----------------------------------------------------------------------------
// 1) ENV yardımcıları
// -----------------------------------------------------------------------------
static std::string getEnvOrDefault(const char* varName, const char* defaultVal) {
    const char* val = std::getenv(varName);
    return (val ? std::string(val) : std::string(defaultVal));
}
static uint16_t getEnvOrDefaultInt(const char* varName, uint16_t defaultVal) {
    const char* val = std::getenv(varName);
    if (!val) return defaultVal;
    return static_cast<uint16_t>(std::stoi(val));
}

// -----------------------------------------------------------------------------
// 2) Bayrak listesi (bit sırası)
//    NOT: Bu listedeki sıraya göre bit indexleri eşlenir (0..N-1).
// -----------------------------------------------------------------------------
static const std::vector<std::string> flagList = {
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
};

// -----------------------------------------------------------------------------
// 3) Base flags: -march=native kaldırıldı (host bağımlılığı yok)
// -----------------------------------------------------------------------------
static std::string getFixedFlags() {
    std::string baseFlags =
        "-c -fpermissive -w "
        "-Wno-implicit-function-declaration -Wno-return-type -Wno-builtin-redeclared "
        "-Wno-implicit-int -Wno-int-conversion "
        "-I/usr/include";

    std::string includesDir = getEnvOrDefault("INCLUDES_DIR", "/users/user42/llvmSS-include");
    baseFlags += " -I" + includesDir;
    return baseFlags;
}

// -----------------------------------------------------------------------------
// 4) 01-bitset -> kanonik flag dizesi
// -----------------------------------------------------------------------------
struct FlagSpec {
    std::string text;
    int group = -1;          // -1: tekil/toggle; >=0: grup kimliği
    int rank  = 0;           // grupta öncelik
    std::string toggleKey;   // "-fX" / "-fno-X" çiftleri için anahtar
    int toggleVal = 0;       // +1: "-fX", -1: "-fno-X"
};

enum GroupId {
    G_OPT=0, G_MARCH, G_FP_MODEL, G_FP_EXC, G_FP_EVAL, G_TLS,
    G_DENORMAL, G_FP_CONTRACT, G_EXCESS_PREC, G_STACK_PROT,
    G_BITFIELDS_SIGN, G_CHAR_SIGN, G_LAXVEC_ENUM
};

static bool startsWith(const std::string& s, const char* pfx) {
    size_t n = std::char_traits<char>::length(pfx);
    return s.size() >= n && std::equal(pfx, pfx+n, s.begin());
}

static void assignGroupAndToggle(FlagSpec& s,
                                 const std::unordered_set<std::string>& hasNo,
                                 const std::unordered_set<std::string>& hasYes)
{
    const std::string& t = s.text;

    // ---- Gruplar ----
    // -O*
    if (t == "-O0") { s.group = G_OPT; s.rank = 0; return; }
    if (t == "-O1") { s.group = G_OPT; s.rank = 1; return; }
    if (t == "-O2") { s.group = G_OPT; s.rank = 2; return; }
    if (t == "-O3") { s.group = G_OPT; s.rank = 3; return; }
    if (t == "-Og") { s.group = G_OPT; s.rank = 2; return; }
    if (t == "-Os") { s.group = G_OPT; s.rank = 2; return; }
    if (t == "-Oz") { s.group = G_OPT; s.rank = 2; return; }
    if (t == "-Ofast") { s.group = G_OPT; s.rank = 4; return; }

    // -march=*
    if (startsWith(t, "-march=")) {
        s.group = G_MARCH;
        if (t == "-march=x86-64") s.rank = 1;
        else if (t == "-march=x86-64-v2") s.rank = 2;
        else if (t == "-march=x86-64-v3") s.rank = 3;
        else s.rank = 0;
        return;
    }

    // -ffp-model=*
    if (startsWith(t, "-ffp-model=")) {
        s.group = G_FP_MODEL;
        if (t == "-ffp-model=precise") s.rank = 1;
        else if (t == "-ffp-model=strict") s.rank = 2;
        else if (t == "-ffp-model=fast") s.rank = 3;
        return;
    }

    // -ffp-exception-behavior=*
    if (startsWith(t, "-ffp-exception-behavior=")) {
        s.group = G_FP_EXC;
        if (t == "-ffp-exception-behavior=ignore") s.rank = 1;
        else if (t == "-ffp-exception-behavior=maytrap") s.rank = 2;
        else if (t == "-ffp-exception-behavior=strict") s.rank = 3;
        return;
    }

    // -ffp-eval-method=*
    if (startsWith(t, "-ffp-eval-method=")) {
        s.group = G_FP_EVAL;
        if (t == "-ffp-eval-method=source") s.rank = 1;
        else if (t == "-ffp-eval-method=double") s.rank = 2;
        else if (t == "-ffp-eval-method=extended") s.rank = 3;
        return;
    }

    // -ffp-contract=*
    if (startsWith(t, "-ffp-contract=")) {
        s.group = G_FP_CONTRACT;
        if (t == "-ffp-contract=off") s.rank = 0;
        else if (t == "-ffp-contract=on") s.rank = 1;
        else if (t == "-ffp-contract=fast") s.rank = 2;
        return;
    }

    // -fexcess-precision=*
    if (startsWith(t, "-fexcess-precision=")) {
        s.group = G_EXCESS_PREC;
        if (t == "-fexcess-precision=standard") s.rank = 1;
        else if (t == "-fexcess-precision=fast") s.rank = 2;
        return;
    }

    // -ftls-model=*
    if (startsWith(t, "-ftls-model=")) {
        s.group = G_TLS;
        if (t == "-ftls-model=global-dynamic") s.rank = 1;
        else if (t == "-ftls-model=local-dynamic") s.rank = 2;
        else if (t == "-ftls-model=initial-exec") s.rank = 3;
        else if (t == "-ftls-model=local-exec") s.rank = 4;
        return;
    }

    // -fdenormal-fp-math=*
    if (startsWith(t, "-fdenormal-fp-math=")) {
        s.group = G_DENORMAL;
        if (t == "-fdenormal-fp-math=ieee") s.rank = 1;
        else if (t == "-fdenormal-fp-math=preserve-sign") s.rank = 2;
        else if (t == "-fdenormal-fp-math=positive-zero") s.rank = 3;
        return;
    }

    // -fsigned-bitfields / -funsigned-bitfields -> grup
    if (t == "-fsigned-bitfields")  { s.group = G_BITFIELDS_SIGN; s.rank = 1; return; }
    if (t == "-funsigned-bitfields"){ s.group = G_BITFIELDS_SIGN; s.rank = 2; return; }

    // -fsigned-char / -funsigned-char -> grup
    if (t == "-fsigned-char")   { s.group = G_CHAR_SIGN; s.rank = 1; return; }
    if (t == "-funsigned-char") { s.group = G_CHAR_SIGN; s.rank = 2; return; }

    // -flax-vector-conversions=*
    if (startsWith(t, "-flax-vector-conversions=")) {
        s.group = G_LAXVEC_ENUM;
        if (t == "-flax-vector-conversions=none") s.rank = 1;
        else if (t == "-flax-vector-conversions=integer") s.rank = 2;
        return;
    }

    // Stack protector seviyesi: no / default / strong / all
    if (t == "-fno-stack-protector") { s.group = G_STACK_PROT; s.rank = 0; return; }
    if (t == "-fstack-protector")    { s.group = G_STACK_PROT; s.rank = 1; return; }
    if (t == "-fstack-protector-strong") { s.group = G_STACK_PROT; s.rank = 2; return; }
    if (t == "-fstack-protector-all"){ s.group = G_STACK_PROT; s.rank = 3; return; }

    // ---- Toggle çiftleri ----
    // -fno-XYZ
    if (startsWith(t, "-fno-")) {
        s.toggleKey = t.substr(5);
        s.toggleVal = -1;
        return;
    }
    // -fXYZ (eşleşen -fno-XYZ varsa)
    if (startsWith(t, "-f") && t.find('=') == std::string::npos) {
        std::string key = t.substr(2);
        if (hasNo.count(key)) {
            s.toggleKey = key;
            s.toggleVal = +1;
            return;
        }
    }

    // Aksi halde: tekil bayrak olarak kalır (s.group = -1, toggleKey boş)
}

static std::vector<FlagSpec> buildSpecs() {
    // Önce tüm -fno-* anahtarlarını ve eşleşen -f* pozitifleri topla
    std::unordered_set<std::string> hasNo, hasYes;
    for (const auto& f : flagList) {
        if (startsWith(f, "-fno-")) hasNo.insert(f.substr(5));
        else if (startsWith(f, "-f") && f.find('=') == std::string::npos) hasYes.insert(f.substr(2));
    }

    std::vector<FlagSpec> specs;
    specs.reserve(flagList.size());
    for (const auto& t : flagList) {
        FlagSpec s; s.text = t;
        assignGroupAndToggle(s, hasNo, hasYes);
        specs.push_back(std::move(s));
    }
    return specs;
}

static const std::vector<FlagSpec>& getSpecs() {
    static const std::vector<FlagSpec> S = buildSpecs();
    return S;
}

static std::bitset<128> readFlagBits(const std::vector<uint8_t>& data) {
    std::bitset<128> bits;
    for (size_t i = 0; i < 16; ++i) {
        uint8_t byte = (2 + i < data.size()) ? data[2 + i] : 0;
        for (int b = 0; b < 8; ++b) {
            bits.set(i * 8 + b, (byte >> b) & 1);
        }
    }
    return bits;
}

static std::string canonicalizeFlagsFromBits(const std::bitset<128>& bits) {
    const auto& specs = getSpecs();
    // Grup kazananları: group -> (rank, specIndex)
    std::map<int, std::pair<int,int>> groupWin;
    // Toggle seçimi: key -> (rank, specIndex); rank: -1=>1, +1=>2 (pozitifi tercih et)
    std::unordered_map<std::string, std::pair<int,int>> toggleSel;
    // Tekiller
    std::vector<std::string> singles;

    for (size_t i = 0; i < specs.size() && i < bits.size(); ++i) {
        if (!bits.test(i)) continue;
        const auto& s = specs[i];

        if (s.group >= 0) {
            auto it = groupWin.find(s.group);
            if (it == groupWin.end() || s.rank > it->second.first) {
                groupWin[s.group] = {s.rank, (int)i};
            }
            continue;
        }
        if (!s.toggleKey.empty()) {
            int r = (s.toggleVal < 0) ? 1 : 2; // deterministik: + olan kazanır
            auto it = toggleSel.find(s.toggleKey);
            if (it == toggleSel.end() || r > it->second.first) {
                toggleSel[s.toggleKey] = {r, (int)i};
            }
            continue;
        }
        // Tekil
        singles.push_back(s.text);
    }

    std::vector<std::string> out;
    out.reserve(groupWin.size() + toggleSel.size() + singles.size());

    for (auto& kv : groupWin) out.push_back(getSpecs()[kv.second.second].text);
    for (auto& kv : toggleSel) out.push_back(getSpecs()[kv.second.second].text);
    for (auto& s : singles) out.push_back(s);

    std::sort(out.begin(), out.end());
    // Stringleştir
    std::string res;
    for (auto& t : out) { res += t; res += ' '; }
    if (!res.empty() && res.back() == ' ') res.pop_back();
    return res;
}

// -----------------------------------------------------------------------------
// 5) Dosya okuma, bayrak çözümleme
// -----------------------------------------------------------------------------
static std::vector<uint8_t> readBinaryFile(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open binary file " << filename << std::endl;
        exit(1);
    }
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

// Yalnızca bayrakları (base hariç) döndür
static std::string decodeFlagsFromBinarySub(const std::vector<uint8_t> &data) {
    auto bits = readFlagBits(data);
    return canonicalizeFlagsFromBits(bits);
}

// Base + kanonik bayraklar
static std::string decodeFlagsFromBinary(const std::vector<uint8_t> &data) {
    return getFixedFlags() + " " + decodeFlagsFromBinarySub(data);
}

// -----------------------------------------------------------------------------
// 6) Program seçimi: 2 bayt indeks, default FP dataset (13,356)
// -----------------------------------------------------------------------------
static std::string generateTestFileName(const std::vector<uint8_t> &data) {
    std::string testFilesDir = getEnvOrDefault("CFILES_DIR", "/users/user42/llvmSS-minimised-corpus");
    if (data.size() < 2) return testFilesDir + "/test_0.c";

    uint16_t rawValue = (uint16_t)data[0] | (uint16_t)data[1] << 8;

    // Varsayılanı FP dataset boyutu olarak ayarla (override: FILE_COUNT env)
    uint16_t fileCount = getEnvOrDefaultInt("FILE_COUNT", 1811);
    uint16_t fileIndex = (fileCount == 0) ? 0 : (rawValue % fileCount);

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "/test_%u.c", fileIndex);
    return testFilesDir + std::string(buffer);
}

// -----------------------------------------------------------------------------
// 7) Text input (opsiyonel) – ikinci satır bayrak dizesi (manuel test için)
// -----------------------------------------------------------------------------
static std::pair<std::string, std::string> parseTextFile(const std::string &filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open text file " << filename << std::endl;
        exit(1);
    }
    std::string sourceFile, flags;
    if (!std::getline(infile, sourceFile)) {
        std::cerr << "Error: Text file " << filename << " is empty or missing source file path." << std::endl;
        exit(1);
    }
    if (!std::getline(infile, flags)) flags = "";
    return std::make_pair(sourceFile, flags);
}

// -----------------------------------------------------------------------------
// 8) Clang derleme
// -----------------------------------------------------------------------------
static int runClangCompilation(const std::string &sourceFile, const std::string &flags) {
    llvm::IntrusiveRefCntPtr<clang::DiagnosticOptions> diagOpts = new clang::DiagnosticOptions();
    llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diags = new clang::DiagnosticsEngine(
        new clang::DiagnosticIDs(),
        diagOpts,
        new clang::TextDiagnosticPrinter(llvm::errs(), diagOpts.get())
    );

    std::string compilerPath = getEnvOrDefault("INSTRUMENTED_CLANG_PATH", "/users/user42/build/bin/clang");
    clang::driver::Driver driver(compilerPath, llvm::sys::getDefaultTargetTriple(), *diags);

    std::vector<std::string> args = { compilerPath, "-x", "c", sourceFile };

    // Flags'i boşluklara göre ayır ve ekle
    std::istringstream flagStream(flags);
    std::string flag;
    while (flagStream >> flag) args.push_back(flag);

    std::vector<const char*> cArgs;
    cArgs.reserve(args.size());
    for (const auto &arg : args) cArgs.push_back(arg.c_str());

    clang::driver::Compilation* rawCompilation = driver.BuildCompilation(cArgs);
    if (!rawCompilation) {
        llvm::errs() << "Error: Failed to build the compilation job.\n";
        return 1;
    }

    std::unique_ptr<clang::driver::Compilation> compilation(rawCompilation);
    llvm::SmallVector<std::pair<int, const clang::driver::Command*>, 4> FailingCommands;
    int result = driver.ExecuteCompilation(*compilation, FailingCommands);

    if (result != 0) {
        llvm::errs() << "Compilation failed with error code " << result << ".\n";
        for (const auto &cmd : FailingCommands) {
            llvm::errs() << "Failed Command: " << cmd.second->getExecutable() << "\n";
        }
    }
    return result;
}

// -----------------------------------------------------------------------------
// 9) main
// -----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "--version") {
        std::cout << "Clang version: " << clang::getClangFullVersion() << std::endl;
        return 0;
    }

    std::string fileBin, fileTxt;
    bool checkerMode = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--filebin") {
            if (i + 1 < argc) fileBin = argv[++i];
            else { std::cerr << "Error: --filebin requires a file path.\n"; return 1; }
        } else if (arg == "--filetxt") {
            if (i + 1 < argc) fileTxt = argv[++i];
            else { std::cerr << "Error: --filetxt requires a file path.\n"; return 1; }
        } else if (arg == "--checker") {
            checkerMode = true;
        }
    }

    if (fileBin.empty() && fileTxt.empty()) {
        std::cerr << "Usage: " << argv[0] << " --filebin <binary_input> [--checker]\n"
                  << "       " << argv[0] << " --filetxt <text_input> [--checker]\n"
                  << "       " << argv[0] << " --version\n";
        return 1;
    }

    std::string sourceFile, flags, subflags;
    std::vector<uint8_t> data;

    if (!fileBin.empty()) {
        data = readBinaryFile(fileBin);
        sourceFile = generateTestFileName(data);
        subflags   = decodeFlagsFromBinarySub(data); // kanonik (base hariç)
        flags      = getFixedFlags() + " " + subflags;
    } else {
        auto parsed = parseTextFile(fileTxt);
        sourceFile = parsed.first;
        flags = parsed.second;
        subflags = flags; // checker çıktısı için
    }

    if (checkerMode) {
        std::cout << "[Checker] Source File: " << sourceFile << "\n";
        std::cout << "[Checker] Fixed Flags: " << getFixedFlags() << "\n";
        std::cout << "[Checker] Flags (canonical): " << subflags << "\n";
        return 0;
    }

    std::cout << "Using Source File: " << sourceFile << std::endl;
    std::cout << "Using Flags: " << flags << std::endl;

    return runClangCompilation(sourceFile, flags);
}
