#include "template.hpp"

int main() {
  ll(N, Q);
  vll(w, x, y, z, Q);
  dsu dsu(N + 1);
  vi a(N + 1);
  rep(i, Q) {
    if (w[i] == 1) {
      ll u = dsu.leader(x[i]);
      ll v = dsu.leader(y[i]);
      if (z[i] & 1) {
        ll tmp = a[v];
        if (a[u]) {
          dsu.merge(v, a[u]);
        }
        if (a[v]) {
          dsu.merge(u, tmp);
        }
        a[dsu.leader(u)] = v;
        a[dsu.leader(v)] = u;
      } else {
        dsu.merge(u, v);
        if (a[u] and a[v]) {
          dsu.merge(a[u], a[v]);
        }
        if (a[u]) {
          a[dsu.leader(u)] = a[u];
        }
        if (a[v]) {
          a[dsu.leader(u)] = a[v];
        }
      }
    } else {
      yes(dsu.same(x[i], y[i]), "YES", "NO");
    }
  }
}
