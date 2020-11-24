#include "template.hpp"

int main() {
  ll(N, W);
  vll(w, v, N);
  vi dp(W + 1);
  rep(i, N) {
    rrep(j, w[i], W + 1) { chmax(dp[j], dp[j - w[i]] + v[i]); }
  }
  ll ans = dp[W];
  out(ans);
}
