#include "comb.hpp"
#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(N, M, K);
  comb<mint> comb(N * M);
  vec<mint> S(max(N, M));
  repi(i, max(N, M) - 1) { S[i] = S[i - 1] + i; }
  mint ans = 0;
  rep(i, N) { ans += M * M * (S[i] + S[N - i - 1]); }
  rep(j, M) { ans += N * N * (S[j] + S[M - j - 1]); }
  ans *= comb.c(N * M - 2, K - 2) / 2;
  out(ans);
}
