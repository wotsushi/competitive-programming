#include "template.hpp"

int main() {
  ll(N);
  vll(A, B, N);
  auto f = [&](ll x) {
    ll res = 0;
    for (ll i = 1; i * i <= x; ++i) {
      if (x % i != 0) {
        continue;
      }
      bool ok = true;
      rep(j, 1, N) { ok &= (A[j] % i == 0) or (B[j] % i == 0); }
      if (ok) {
        chmax(res, i);
      }
      ok = true;
      rep(j, 1, N) { ok &= A[j] % (x / i) == 0 or B[j] % (x / i) == 0; }
      if (ok) {
        chmax(res, x / i);
      }
    }
    return res;
  };
  ll ans = max(f(A[0]), f(B[0]));
  out(ans);
}
