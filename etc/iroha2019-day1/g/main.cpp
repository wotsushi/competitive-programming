#include "template.hpp"

int main() {
  ll(N, M, K);
  vll(A, N);
  auto dp = vecv(ll, M + 1, K, -INF);
  dp[0][0] = 0;
  rep(i, N) {
    auto tmp = vecv(ll, M + 1, K, -INF);
    rep(j, M + 1) {
      rep(k, K) {
        if (j < M) {
          chmax(tmp[j + 1][0], dp[j][k] + A[i]);
        }
        if (k < K - 1) {
          chmax(tmp[j][k + 1], dp[j][k]);
        }
      }
    }
    dp = tmp;
  }
  ll ans = -1;
  rep(k, K) { chmax(ans, dp[M][k]); }
  out(ans);
}
