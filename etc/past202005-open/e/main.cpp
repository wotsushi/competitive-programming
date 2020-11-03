#include "graph.hpp"
#include "template.hpp"

int main() {
  ll(N, M, Q);
  graph<ll> G(N, M);
  cin >> G;
  vll(c, N);
  c.insert(c.begin(), 0);
  rep(_, Q) {
    ll(t);
    if (t == 1) {
      ll(x);
      out(c[x]);
      for (auto [i, _] : G[x]) {
        c[i] = c[x];
      }
    } else {
      ll(x, y);
      out(c[x]);
      c[x] = y;
    }
  }
}
