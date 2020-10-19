#include "template.hpp"

int main() {
  ll(D, G);
  vll(p, c, D);
  ll ans = INF;
  rep(q, 1 << D) {
    ll s = 0;
    ll x = 0;
    rep(i, D) {
      if (q >> i & 1) {
        x += p[i];
        s += 100 * (i + 1) * p[i] + c[i];
      }
    }
    rrep(i, D) {
      if (not(q >> i & 1)) {
        ll k = clamp((G - s + 100 * (i + 1) - 1) / (100 * (i + 1)), 0LL, p[i]);
        x += k;
        s += 100 * (i + 1) * k;
      }
    }
    chmin(ans, x);
  }
  out(ans);
}
