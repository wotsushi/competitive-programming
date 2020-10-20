#include "template.hpp"

int main() {
  ll(N, M);
  vll(L, R, M);
  ll l = 1;
  ll r = N;
  rep(i, M) {
    chmax(l, L[i]);
    chmin(r, R[i]);
  }
  ll ans = max(0LL, r - l + 1);
  out(ans);
}
