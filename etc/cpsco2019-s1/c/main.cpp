#include "template.hpp"

int main() {
  ll(N, K);
  vll(A, N);
  auto f = def([&](auto &&f, ll k, ll i, ll s) -> ll {
    ll res;
    if (k == K) {
      res = 0;
      rep(_, 10) {
        ll r = s % 10;
        res += r / 5 + r % 5;
        s /= 10;
      }
      return res;
    }
    res = INF;
    rep(j, i, N - (K - k - 1)) { chmin(res, f(k + 1, j + 1, s + A[j])); }
    return res;
  });
  ll ans = f(0, 0, 0);
  out(ans);
}
