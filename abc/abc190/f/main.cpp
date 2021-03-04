#include "template.hpp"

int main() {
  ll(N);
  vll(a, N);
  fenwick_tree<ll> bit(N);
  ll ans = 0;
  rep(i, N) {
    ans += bit.sum(a[i] + 1, N);
    bit.add(a[i], 1);
  }
  rep(k, N) {
    out(ans);
    ans += N - 1 - 2 * a[k];
  }
}
