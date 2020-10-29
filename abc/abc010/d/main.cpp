#include "template.hpp"

int main() {
  ll(N, G, E);
  vll(p, G);
  vll(a, b, E);
  mf_graph<ll> g(N + 1);
  rep(i, E) {
    g.add_edge(a[i], b[i], 1);
    g.add_edge(b[i], a[i], 1);
  }
  each(x, p) { g.add_edge(x, N, 1); }
  ll ans = g.flow(0, N);
  out(ans);
}
