#include "template.hpp"

int main() {
  ll(N);
  vll(c, N);
  vi dp(N + 1, INF);
  dp[0] = 0;
  each(x, c) { *lower_bound(ALL(dp), x) = x; }
  rrepi(i, N) {
    if (dp[i] < INF) {
      out(N - i);
      break;
    }
  }
}
