#include "template.hpp"

int main() {
  ll(N, K);
  vvll(A, N);
  ll ok = INF;
  ll ng = -1;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    auto dp = vec(ll, N + 1, N + 1);
    repi(i, N) {
      repi(j, N) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] +
                   (A[i - 1][j - 1] > mid);
      }
    }
    bool good = false;
    repi(i, K, N) {
      repi(j, K, N) {
        if (dp[i][j] - dp[i - K][j] - dp[i][j - K] + dp[i - K][j - K] <=
            K * K / 2) {
          good = true;
        }
      }
    }
    if (good) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  out(ok);
}
