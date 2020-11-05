#include "template.hpp"

int main() {
  ll(H, W, K, V);
  auto A = vec(ll, H, W);
  rep(i, H) {
    rep(j, W) { cin >> A[i][j]; }
  }
  auto dp = vec(ll, H + 1, W + 1);
  repi(i, H) {
    repi(j, W) {
      dp[i][j] =
          A[i - 1][j - 1] + K + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
  }
  ll ans = 0;
  rep(i, H) {
    rep(j, W) {
      repi(u, i + 1, H) {
        repi(v, j + 1, W) {
          if (dp[u][v] - dp[i][v] - dp[u][j] + dp[i][j] <= V) {
            chmax(ans, (u - i) * (v - j));
          }
        }
      }
    }
  }
  out(ans);
}
