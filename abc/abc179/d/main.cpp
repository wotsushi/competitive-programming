#include "template.hpp"
using mint = modint998244353;

int main() {
  ll(N, K);
  vll(L, R, K);
  vec<mint> dp(N + 1);
  dp[1] = 1;
  repi(i, 2, N) {
    dp[i] = dp[i - 1];
    rep(j, K) { dp[i] += dp[max(0LL, i - L[j])] - dp[max(0LL, i - R[j] - 1)]; }
  }
  mint ans = dp[N] - dp[N - 1];
  out(ans);
}
