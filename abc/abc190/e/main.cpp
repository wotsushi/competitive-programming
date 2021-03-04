#include "dijkstra.hpp"
#include "graph.hpp"
#include "template.hpp"

int main() {
  ll(N, M);
  graph<ll> G(N, M);
  cin >> G;
  ll(K);
  vll(C, K);
  ll P = 1 << K;
  vvi d(K);
  rep(i, K) { d[i] = dijkstra(G, C[i]); }
  graph<ll> H(K * P, 0, false, true);
  auto dp = vecv(ll, P, K, INF);
  rep(i, K) { dp[1 << i][i] = 0; }
  rep(p, P) {
    rep(i, K) {
      if ((p & (1 << i)) == 0) {
        continue;
      }
      rep(j, K) {
        if ((p & (1 << j)) == 0) {
          continue;
        }
        chmin(dp[p][i], dp[p - (1 << i)][j] + d[j][C[i]]);
      }
    }
  }
  ll ans = INF;
  rep(i, K) { chmin(ans, dp[P - 1][i]); }
  if (ans == INF) {
    ans = -1;
  } else {
    ++ans;
  }
  out(ans);
}
