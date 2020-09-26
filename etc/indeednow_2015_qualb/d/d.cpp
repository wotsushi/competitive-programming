#include "template.hpp"

int main() {
  ll(N, C);
  vll(a, N);
  vvi X(C + 1);
  rep(i, N) { X[a[i]].push_back(i); }
  repi(i, C) {
    ll l = 0;
    ll ans = (N + 1) * N / 2;
    X[i].push_back(N);
    each(r, X[i]) {
      ans -= (r - l + 1) * (r - l) / 2;
      l = r + 1;
    }
    out(ans);
  }
}
