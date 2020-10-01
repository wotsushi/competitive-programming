#include "template.hpp"

int main() {
  ll(H, W);
  vin(string, S, H);
  auto dp = vecv(bool, H + 1, W + 1, true);
  rrep(i, H) {
    rrep(j, W) {
      if (S[i][j] == '#') {
        dp[i][j] = true;
      } else {
        dp[i][j] = not(dp[i + 1][j] and dp[i][j + 1] and dp[i + 1][j + 1]);
      }
    }
  }
  yes(dp[0][0], "First", "Second");
}
