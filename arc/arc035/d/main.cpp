#include "template.hpp"

long double op(long double a, long double b) { return a + b; }

long double e() { return 0; }

const ll L = 1e6;

int main() {
  ll(N);
  vll(p, q, N);
  vec<long double> fact(L + 1);
  rep(i, L) { fact[i + 1] = fact[i] + log(i + 1); }
  auto f = [&](ll i) -> long double {
    ll n = p[i + 1] - p[i] + q[i + 1] - q[i];
    ll r = p[i + 1] - p[i];
    return fact[n] - (fact[r] + fact[n - r]);
  };
  vec<long double> C(N - 1);
  rep(i, N - 1) { C[i] = f(i); }
  segtree<long double, op, e> seg(C);
  ll(Q);
  rep(i, Q) {
    ll(t);
    if (t == 1) {
      ll(k, a, b);
      --k;
      p[k] = a;
      q[k] = b;
      if (k < N - 1) {
        seg.set(k, f(k));
      }
      if (k > 0) {
        seg.set(k - 1, f(k - 1));
      }
    } else {
      ll(l_1, r_1, l_2, r_2);
      yes(seg.prod(l_1 - 1, r_1 - 1) > seg.prod(l_2 - 1, r_2 - 1), "FIRST",
          "SECOND");
    }
  }
}
