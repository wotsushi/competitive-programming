#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(H, W);
  vin(string, S, H);
  auto dp = vec(mint, 4, H + 1, W + 1);
  repi(i, H) {
    repi(j, W) {
      if (S[i - 1][j - 1] == '#') {
        continue;
      }
      if (i == 1 and j == 1) {
        dp[0][i][j] = 1;
      } else {
        dp[0][i][j] = dp[1][i][j - 1] + dp[2][i - 1][j] + dp[3][i - 1][j - 1];
      }
      dp[1][i][j] = dp[1][i][j - 1] + dp[0][i][j];
      dp[2][i][j] = dp[2][i - 1][j] + dp[0][i][j];
      dp[3][i][j] = dp[3][i - 1][j - 1] + dp[0][i][j];
    }
  }
  out(dp[0][H][W]);
}
