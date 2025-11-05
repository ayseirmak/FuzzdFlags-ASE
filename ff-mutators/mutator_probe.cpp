#include <dlfcn.h>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using init_fn   = void*   (*)(void*, unsigned int);
using fuzz_fn   = size_t  (*)(void*, unsigned char*, size_t,
                              unsigned char**, unsigned char*, size_t, size_t);
using deinit_fn = void    (*)(void*);
using desc_fn   = const char* (*)(void*, size_t);

static std::vector<unsigned char> read_file(const char* path) {
  std::ifstream f(path, std::ios::binary);
  if (!f) throw std::runtime_error(std::string("cannot open: ") + path);
  return std::vector<unsigned char>((std::istreambuf_iterator<char>(f)),
                                    std::istreambuf_iterator<char>());
}

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " /path/to/libgrayc_const.so seeds/seed0.c [iters]\n";
    return 1;
  }
  const char* so_path   = argv[1];
  const char* seed_path = argv[2];
  int iters = (argc > 3) ? std::max(1, std::atoi(argv[3])) : 3;

  void* h = dlopen(so_path, RTLD_LAZY);
  if (!h) { std::cerr << "dlopen: " << dlerror() << "\n"; return 1; }

  auto init   = (init_fn)   dlsym(h, "afl_custom_init");
  auto fuzz   = (fuzz_fn)   dlsym(h, "afl_custom_fuzz");
  auto deinit = (deinit_fn) dlsym(h, "afl_custom_deinit");
  auto desc   = (desc_fn)   dlsym(h, "afl_custom_describe");
  if (!init || !fuzz || !deinit) { std::cerr << "missing afl_custom_* hooks\n"; return 1; }

  std::vector<unsigned char> in = read_file(seed_path);
  void* state = init(nullptr, 1337u);
  if (desc) std::cerr << "[plugin] " << desc(state, 1024) << "\n";

  for (int i = 0; i < iters; ++i) {
    unsigned char* out_buf = nullptr;
    size_t out_sz = fuzz(state, in.data(), in.size(), &out_buf, nullptr, 0, 1<<20);
    if (!out_sz || !out_buf) { std::cerr << "mutation " << (i+1) << ": 0 bytes\n"; continue; }

    std::string mutated((char*)out_buf, (char*)out_buf + out_sz);
    std::cout << "------ mutation #" << (i+1) << " ------\n" << mutated << "\n";
    free(out_buf);
    in.assign(mutated.begin(), mutated.end());
  }

  deinit(state);
  dlclose(h);
  return 0;
}
