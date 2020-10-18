#include "template.hpp"

const ll K = 50;

int main() {
  ll(N, X, M);
  auto dp = vec(ll, K + 1, M);
  auto acc = vec(ll, K + 1, M);
  rep(i, M) {
    dp[0][i] = (i * i) % M;
    acc[0][i] = i;
  }
  rep(k, K) {
    rep(i, M) {
      ll j = dp[k][i];
      dp[k + 1][i] = dp[k][j];
      acc[k + 1][i] = acc[k][i] + acc[k][j];
    }
  }
  ll ans = 0;
  ll x = X;
  rrep(k, K) {
    if ((N >> k) & 1) {
      ans += acc[k][x];
      x = dp[k][x];
    }
  }
  out(ans);
}
