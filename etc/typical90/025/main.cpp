#include "template.hpp"

ll p(ll x, ll k) {
  ll res = 1;
  rep(_, k) { res *= x; }
  return res;
}

ll q(ll i, ll j, ll k, ll l) { return p(2, i) * p(3, j) * p(5, k) * p(7, l); }

ll f(ll m) {
  ll res = 1;
  while (m > 0) {
    res *= m % 10;
    m /= 10;
  }
  return res;
}

int main() {
  ll(N, B);
  ll ans = B <= N and f(B) == 0;
  for (ll i = 0; B + q(i, 0, 0, 0) <= N; ++i) {
    for (ll j = 0; B + q(i, j, 0, 0) <= N; ++j) {
      for (ll k = 0; B + q(i, j, k, 0) <= N; ++k) {
        for (ll l = 0; B + q(i, j, k, l) <= N; ++l) {
          ll m = B + q(i, j, k, l);
          ans += m - f(m) == B;
        }
      }
    }
  }
  out(ans);
}
