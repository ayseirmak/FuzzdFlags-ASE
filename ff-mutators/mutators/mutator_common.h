// mutator_common.h  (compile into each .so)
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <cstring>

struct SeedParts {
  std::vector<uint8_t> flags;
  std::string program;
  bool ok = false;
};

static inline SeedParts parse_seed(const uint8_t *buf, size_t len) {
  SeedParts sp;
  if (!len) return sp;
  const char *p = (const char *)buf;
  const char *nl = (const char *)memchr(p, '\n', len);
  if (!nl) { sp.ok = true; sp.program.assign(p, p + len); return sp; } // no header → only program
  std::string header(p, nl);
  size_t off = (nl - p) + 1;
  sp.program.assign((const char*)buf + off, (const char*)buf + len);
  if (header.rfind("//FFHEX:", 0) == 0) {
    std::string rest = header.substr(8);
    size_t i=0;
    while (i < rest.size()) {
      while (i<rest.size() && (rest[i]==' '||rest[i]==','||rest[i]=='\t')) ++i;
      size_t j=i;
      while (j<rest.size() && rest[j]!=',' && rest[j]!=' ' && rest[j]!='\t') ++j;
      if (j>i) {
        std::string tok = rest.substr(i, j-i);
        if (tok.rfind("0x",0)==0 || tok.rfind("0X",0)==0) tok = tok.substr(2);
        char *end=nullptr; long v = strtol(tok.c_str(), &end, 16);
        if (end && *end==0 && v >= 0 && v <= 255) sp.flags.push_back((uint8_t)v);
      }
      i=j;
    }
  }
  sp.ok = true;
  return sp;
}

static inline std::string encode_hex(const std::vector<uint8_t> &v) {
  static const char *hexd = "0123456789ABCDEF";
  std::string s = "//FFHEX:";
  for (uint8_t b : v) { s.push_back(' '); s.push_back(hexd[(b>>4)&0xF]); s.push_back(hexd[b&0xF]); }
  s.push_back('\n');
  return s;
}
