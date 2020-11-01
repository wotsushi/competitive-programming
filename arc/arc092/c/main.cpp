#include "template.hpp"

int main() {
  ll(N);
  vll(a, b, N);
  vll(c, d, N);
  mf_graph<ll> G(2 * N + 2);
  ll src = 2 * N;
  ll sink = 2 * N + 1;
  rep(i, N) {
    G.add_edge(src, i, 1);
    G.add_edge(i + N, sink, 1);
    rep(j, N) {
      if (a[i] < c[j] and b[i] < d[j]) {
        G.add_edge(i, j + N, 1);
      }
    }
  }
  ll ans = G.flow(src, sink);
  out(ans);
}
