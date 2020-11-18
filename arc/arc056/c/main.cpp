#include "template.hpp"

int main() {
  ll(N, K);
  vvll(w, N);
  vi dp(1 << N);
  vi f(1 << N);
  rep(k, 1, 1 << N) {
    f[k] = -(__builtin_popcount(k) - 1) * K;
    rep(i, N) {
      rep(j, i + 1, N) {
        if ((k & (1 << i)) and (k & (1 << j))) {
          f[k] += w[i][j];
        }
      }
    }
    for (ll l = k; l > 0; l = (l - 1) & k) {
      chmax(dp[k], f[l] + dp[k - l]);
    }
  }
  ll ans = N * K + dp[(1 << N) - 1];
  rep(i, N) {
    rep(j, i + 1, N) { ans -= w[i][j]; }
  }
  out(ans);
}
