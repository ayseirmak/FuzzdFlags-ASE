a() {
  int b = 0, c = 0;
  for (;; a) {
    c++;
    if (c <= 14)
      continue;
    b++;
    if (b <= 45)
      continue;
    return;
  }
}
