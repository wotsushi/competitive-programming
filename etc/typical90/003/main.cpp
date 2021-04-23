#include "graph.hpp"
#include "template.hpp"
#include "tree.hpp"

int main() {
  ll(N);
  graph<ll> G(N, N - 1);
  cin >> G;
  tree<ll> T(G);
  ll r = 1;
  repi(i, N) {
    if (T.depth(i) > T.depth(r)) {
      r = i;
    }
  }
  tree<ll> S(G, r);
  ll ans = 0;
  repi(i, N) { chmax(ans, S.depth(i)); }
  ++ans;
  out(ans)
}
