#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(N, K);
  STR(S);
  auto dp = vec(mint, N + 1, K + 1, K + 1);
  dp[0][0][0] = 1;
  rep(k, N) {
    repi(i, 0, K) {
      repi(j, 0, K) {
        if (S[k] != '1' and i < K) {
          dp[k + 1][i + 1][max(0LL, j - 1)] += dp[k][i][j];
        }
        if (S[k] != '0' and j < K) {
          dp[k + 1][max(0LL, i - 1)][j + 1] += dp[k][i][j];
        }
      }
    }
  }
  mint ans = 0;
  repi(i, 0, K) {
    repi(j, 0, K) { ans += dp[N][i][j]; }
  }
  out(ans.val());
}
