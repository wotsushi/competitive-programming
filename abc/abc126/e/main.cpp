#include "template.hpp"

int main() {
  ll(N, M);
  vll(X, Y, Z, M);
  dsu dsu(N + 1);
  rep(i, M) { dsu.merge(X[i], Y[i]); }
  ll ans = 0;
  repi(i, N) { ans += dsu.leader(i) == i; }
  out(ans);
}
