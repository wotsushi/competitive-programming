#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(N);
  vll(D, N);
  SORT(D);
  auto dp = vec(mint, N + 1, 5);
  dp[0][0] = 1;
  rep(i, N) {
    dp[i + 1][0] = 1;
    rep(j, 4) {
      dp[i + 1][j + 1] =
          dp[i][j + 1] + dp[upper_bound(ALL(D), D[i] / 2) - D.begin()][j];
    }
  }
  out(dp[N][4]);
}
