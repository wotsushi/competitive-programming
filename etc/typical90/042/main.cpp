#include "template.hpp"

using mint = modint1000000007;

int main() {
  ll(K);
  if (K % 9 > 0) {
    out(0);
    return 0;
  }
  vec<mint> dp(K + 1);
  dp[0] = 1;
  rep(i, K) {
    repi(j, 9) {
      if (i + j <= K) {
        dp[i + j] += dp[i];
      }
    }
  }
  mint ans = dp[K];
  out(ans);
}
