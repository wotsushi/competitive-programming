#include "template.hpp"

int main() {
  ll(N, M);
  vll(a, M);
  vi T(N);
  rep(i, M) { T[a[i] - 1] = i + 1; }
  vii P(N);
  rep(i, N) { P[i] = {-T[i], i + 1}; }
  SORT(P);
  for (auto [_, ans] : P) {
    out(ans);
  }
}
