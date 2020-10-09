#include "template.hpp"

ll op(ll a, ll b) { return max(a, b); }

ll e() { return 0; }

int main() {
  ll(N, K);
  vll(A, N);
  ll M = *max_element(ALL(A));
  segtree<ll, op, e> seg(M + 1);
  each(a, A) {
    seg.set(a, 1 + seg.prod(max(0LL, a - K), min(M + 1, a + K + 1)));
  }
  out(seg.all_prod());
}
