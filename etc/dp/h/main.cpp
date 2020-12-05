#include "template.hpp"

using mint = modint1000000007;

int main() {
  ll(H, W);
  vin(string, a, H);
  auto dp = vec(mint, H + 1, W + 1);
  dp[1][1] = 1;
  a[0][0] = '#';
  repi(i, H) {
    repi(j, W) {
      if (a[i - 1][j - 1] == '#') {
        continue;
      }
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  mint ans = dp[H][W];
  out(ans);
}
