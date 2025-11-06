// grayc_jump_custom_mutator.cpp
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "mutator_common.h"

#include "JumpMutator.h"                    // already has FrontendAction(std::string *out)
#include "../utils-fuzzer/GrayCCustomRandom.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Tooling/CompilationDatabase.h"

using namespace clang;
using namespace clang::tooling;

static inline uint64_t fnv1a64(const unsigned char *s) {
  // filename → 64-bit hash (deterministic cross-platform)
  const uint64_t FNV_OFFSET = 1469598103934665603ULL;
  const uint64_t FNV_PRIME  = 1099511628211ULL;
  uint64_t h = FNV_OFFSET;
  if (!s) return h;
  while (*s) { h ^= (uint64_t)(*s++); h *= FNV_PRIME; }
  return h;
}

static inline uint64_t mix64(uint64_t x) {
  // SplitMix64-style finalizer: good avalanche for seed mixing
  x ^= x >> 33;
  x *= 0xff51afd7ed558ccdULL;
  x ^= x >> 33;
  x *= 0xc4ceb9fe1a85ec53ULL;
  x ^= x >> 33;
  return x;
}

static bool run_jump_on_string(const std::string &src,
                               std::string &out,
                               unsigned long seed) {
  // Small discrete choices: break/continue, placement, etc.
  GrayCCustomRandom::CreateInstance(seed, 50);
  FixedCompilationDatabase compDb(".", {"-x","c","-I/usr/include"});
  ClangTool tool(compDb, {"in_mem.c"});
  tool.mapVirtualFile("in_mem.c", src);

  class Factory : public FrontendActionFactory {
    std::string &Out;
  public:
    explicit Factory(std::string &o) : Out(o) {}
    std::unique_ptr<FrontendAction> create() override {
      return std::make_unique<JumpMutatorFrontendAction>(&Out);
    }
  } factory(out);

  int res = tool.run(&factory);
  GrayCCustomRandom::DeleteInstance(seed);
  return res == 0 && !out.empty();
}

extern "C" {
  typedef struct afl_state afl_state_t;
  struct FFState {
    afl_state_t *afl;   
    uint64_t     base;  
    uint64_t     entry; 
    uint64_t     iter;  
  };
  void* afl_custom_init(afl_state_t* afl, unsigned int seed) {
    auto *st = new FFState{afl, (uint64_t)seed, 0, 0};
    return st;
  }
  void afl_custom_deinit(void *data) {
    delete static_cast<FFState*>(data);
  }
  unsigned char afl_custom_queue_get(void *data, const unsigned char *filename) {
    auto *st = static_cast<FFState*>(data);
    st->entry = mix64(fnv1a64(filename));
    st->iter  = 0;
    return 1;
  }
  const char *afl_custom_describe(void *, size_t) { return "grayc-jump"; }
  size_t afl_custom_fuzz(void *data,
                         unsigned char *buf, size_t buf_size,
                         unsigned char **out_buf,
                         unsigned char *add_buf, size_t add_buf_size,
                         size_t max_size) {
    auto *st = static_cast<FFState*>(data);
    uint64_t per_call_seed = mix64(st->base ^ st->entry ^ (++st->iter));
    SeedParts sp = parse_seed(buf, buf_size);
    if (!sp.ok) return 0;
    std::string mutated;
    if (!run_jump_on_string(sp.program, mutated, (unsigned long)per_call_seed)) return 0;

    std::string out = encode_hex(sp.flags) + mutated;
    if (max_size && out.size() > max_size) return 0;
    *out_buf = (unsigned char*)malloc(out.size());
    memcpy(*out_buf, out.data(), out.size());
    return out.size();
  }
}
