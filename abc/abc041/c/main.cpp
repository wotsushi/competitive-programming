#include "template.hpp"

int main() {
  ll(N);
  vll(a, N);
  vii p(N);
  rep(i, N) { p[i] = {a[i], i + 1}; }
  RSORT(p);
  for (auto [_, ans] : p) {
    out(ans);
  }
}
