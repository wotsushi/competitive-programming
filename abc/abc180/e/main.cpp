#include "dijkstra.hpp"
#include "graph.hpp"
#include "template.hpp"

int main() {
  ll(N);
  vll(X, Y, Z, N);
  ll M = 1 << N;
  auto dp = vecv(ll, M, N, INF);
  dp[0][0] = 0;
  repi(k, M - 1) {
    rep(i, N) {
      rep(j, N) {
        if ((k >> i) & 1) {
          chmin(dp[k][i], dp[k - (1 << i)][j] + abs(X[i] - X[j]) +
                              abs(Y[i] - Y[j]) + max(0LL, Z[i] - Z[j]));
        }
      }
    }
  }
  out(dp[(1 << N) - 1][0]);
}
