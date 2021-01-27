#include "graph.hpp"
#include "template.hpp"
#include "tree.hpp"

int main() {
  ll(N);
  vll(a, b, N - 1);
  ll(Q);
  vll(t, e, x, Q);

  graph<ll> G(N);
  rep(i, N - 1) { G.add(a[i], b[i]); }
  tree<ll> T(G);
  vi p(N + 1);
  rep(i, Q) {
    ll u, v;
    if (t[i] == 1) {
      u = a[e[i] - 1];
      v = b[e[i] - 1];
    } else {
      u = b[e[i] - 1];
      v = a[e[i] - 1];
    }
    if (T.depth(u) < T.depth(v)) {
      p[1] += x[i];
      p[v] -= x[i];
    } else {
      p[u] += x[i];
    }
  }
  vi ans(N + 1);
  auto f = def([&](auto&& f, ll i, ll y) -> void {
    ans[i] = y + p[i];
    for (auto [j, _] : T[i]) {
      f(j, ans[i]);
    }
  });
  f(1, 0);
  repi(i, N) { out(ans[i]); }
}
