#include "template.hpp"

int main() {
  ll(N, W);
  vll(w, v, N);
  ll V = 0;
  each(v_i, v) { V += v_i; }
  vi dp(V + 1, INF);
  dp[0] = 0;
  rep(i, N) {
    rrepi(j, v[i], V) { chmin(dp[j], dp[j - v[i]] + w[i]); }
  }
  ll ans;
  rrepi(i, V) {
    if (dp[i] <= W) {
      ans = i;
      break;
    }
  }
  out(ans);
}
