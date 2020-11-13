#include "compress.hpp"
#include "template.hpp"

int main() {
  ll(N);
  vll(A, B, N);
  vi X;
  rep(i, N) { X.push_back(A[i]); }
  rep(i, N) { X.push_back(B[i]); }
  vi Y = compress(X);
  dsu dsu(2 * N);
  vb loop(2 * N);
  rep(i, N) {
    ll u = dsu.leader(Y[i]);
    ll v = dsu.leader(Y[i + N]);
    if (u == v) {
      loop[u] = true;
    }
    dsu.merge(u, v);
    loop[dsu.leader(u)] = loop[u] or loop[v];
  }
  ll ans = 0;
  rep(i, 2 * N) {
    if (dsu.leader(i) == i) {
      if (loop[i]) {
        ans += dsu.size(i);
      } else {
        ans += dsu.size(i) - 1;
      }
    }
  }
  out(ans);
}
