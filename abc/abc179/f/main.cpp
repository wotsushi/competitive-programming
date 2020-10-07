#include "template.hpp"

ll op(ll a, ll b) { return min(a, b); }

ll e() { return INF; }

int main() {
  ll(N, Q);
  vll(t, x, Q);
  segtree<ll, op, e> W(N - 2), H(N - 2);
  ll ans = (N - 2) * (N - 2);
  rep(i, Q) {
    if (t[i] == 1) {
      ll j = min(W.prod(x[i] - 2, N - 2), N - 2);
      ans -= j;
      if (j >= 1) {
        H.set(j - 1, min(x[i] - 2, H.get(j - 1)));
      }
    } else {
      ll j = min(H.prod(x[i] - 2, N - 2), N - 2);
      ans -= j;
      if (j >= 1) {
        W.set(j - 1, min(x[i] - 2, W.get(j - 1)));
      }
    }
  }
  out(ans);
}
