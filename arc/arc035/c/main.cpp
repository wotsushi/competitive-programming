#include "template.hpp"

int main() {
  ll(N, M);
  vll(A, B, C, M);
  ll(K);
  vll(X, Y, Z, K);
  auto dp = vecv(ll, N, N, INF);
  rep(i, N) { dp[i][i] = 0; }
  rep(i, M) {
    dp[A[i] - 1][B[i] - 1] = C[i];
    dp[B[i] - 1][A[i] - 1] = C[i];
  }
  rep(k, N) {
    rep(i, N) {
      rep(j, N) { chmin(dp[i][j], dp[i][k] + dp[k][j]); }
    }
  }
  rep(k, K) {
    ll x = X[k] - 1;
    ll y = Y[k] - 1;
    chmin(dp[x][y], Z[k]);
    chmin(dp[y][x], Z[k]);
    ll ans = 0;
    rep(i, N) {
      rep(j, N) {
        chmin(dp[i][j], min(dp[i][x] + dp[x][y] + dp[y][j],
                            dp[i][y] + dp[y][x] + dp[x][j]));
        ans += dp[i][j];
      }
    }
    ans /= 2;
    out(ans);
  }
}
