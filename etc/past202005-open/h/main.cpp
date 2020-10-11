#include "template.hpp"

int main() {
  ll(N, L);
  vll(x, N);
  vll(T, 3);
  vi dp(L + 4, INF);
  vb H(L);
  each(e, x) { H[e] = true; }
  dp[0] = 0;
  repi(i, L) {
    ch(min, dp[i], dp[i - 1] + T[0] + H[i] * T[2]);
    if (i >= 2) {
      ch(min, dp[i], dp[i - 2] + T[0] + T[1] + H[i] * T[2]);
    }
    if (i >= 4) {
      ch(min, dp[i], dp[i - 4] + T[0] + 3 * T[1] + H[i] * T[2]);
    }
  }
  ll ans = min({
      dp[L],
      dp[L - 1] + T[0] / 2 + T[1] / 2,
      dp[L - 2] + T[0] / 2 + 3 * T[1] / 2,
      dp[L - 3] + T[0] / 2 + 5 * T[1] / 2,
  });
  out(ans);
}
