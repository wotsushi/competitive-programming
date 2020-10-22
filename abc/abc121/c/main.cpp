#include "template.hpp"

int main() {
  ll(N, M);
  vll(A, B, N);
  vii P(N);
  rep(i, N) { P[i] = {A[i], B[i]}; }
  SORT(P);
  ll ans = 0;
  for (auto [a, b] : P) {
    ans += min(b, M) * a;
    M -= min(b, M);
  }
  out(ans);
}
