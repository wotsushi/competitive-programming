#include "template.hpp"

int main() {
  STR(S);
  STR(K);
  set<char> used;
  each(c, K) { used.insert(c); }
  double ans = 0;
  ll N = 0;
  each(c, S) {
    N += 1 - used.count(c);
    ans += used.count(c);
    used.insert(c);
  }
  ll M = 36 - K.size();
  auto dp = vec(double, N + 1, M + 1);
  repi(i, N) {
    repi(j, i, M) {
      dp[i][j] += 1. / j * (dp[i - 1][j - 1] + 1) +
                  1. * (i - 1) / j * (dp[i - 1][j - 1] + 3) +
                  1. * (j - i) / j * (dp[i][j - 1] + 2);
    }
  }
  ans += dp[N][M];
  fout(ans);
}
