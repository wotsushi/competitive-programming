#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(N);
  in(char, c_AA, c_AB, c_BA, c_BB);
  mint ans;
  auto dp = vec(mint, N, 2);
  dp[0][0] = 1;
  if (c_AB == 'A' and c_AA == 'A' or c_AB == 'B' and c_BB == 'B') {
    dp[N - 1][1] = 1;
  } else if (c_AB == 'A' and c_AA == 'B' and c_BA == 'A' or
             c_AB == 'B' and c_BB == 'A' and c_BA == 'B') {
    rep(i, N - 1) {
      dp[i + 1][0] = dp[i][0] + dp[i][1];
      dp[i + 1][1] = dp[i][0];
    }
  } else {
    dp[1][1] = 1;
    rep(i, 1, N - 1) {
      dp[i + 1][0] = dp[i][0] + dp[i][1];
      dp[i + 1][1] = dp[i][0] + dp[i][1];
    }
  }
  ans = dp[N - 1][1];
  out(ans);
}
