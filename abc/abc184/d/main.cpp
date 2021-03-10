#include "template.hpp"

const ll M = 100;

int main() {
  ll(A, B, C);
  auto dp = vec(double, M + 1, M + 1, M + 1);
  rrep(i, M) {
    rrep(j, M) {
      rrep(k, M) {
        if (i == 0 and j == 0 and k == 0) {
          continue;
        }
        dp[i][j][k] =
            (dp[i + 1][j][k] * i + dp[i][j + 1][k] * j + dp[i][j][k + 1] * k) /
                (i + j + k) +
            1;
      }
    }
  }
  double ans = dp[A][B][C];
  fout(ans);
}
