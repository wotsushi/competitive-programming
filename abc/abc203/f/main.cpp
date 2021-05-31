#include "template.hpp"

const ll M = 50;

int main() {
  ll(N, K);
  vll(A, N);
  A.push_back(0);
  SORT(A);
  auto dp = vecv(ll, N + 1, M, INF);
  dp[N][0] = 0;
  rrepi(i, 1, N) {
    rep(j, M) { chmin(dp[i - 1][j], dp[i][j] + 1); }
    ll H = A[i];
    ll k = upper_bound(ALL(A), H / 2) - A.begin() - 1;
    rep(j, M - 1) { chmin(dp[k][j + 1], dp[i][j]); }
  }
  rep(j, M) {
    if (dp[0][j] <= K) {
      cout << j << ' ' << dp[0][j] << endl;
      break;
    }
  }
}
