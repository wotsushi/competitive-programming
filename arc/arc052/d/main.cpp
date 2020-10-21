#include "template.hpp"
using mint = modint;

const ll N = 11;
const ll S = 100;

int main() {
  ll(K, M);
  if (K > 1e5) {
    ll ans = -1;
    for (ll i = 0; i <= M; i += K) {
      rep(j, 100) {
        ll s = 0;
        ll x = i + j;
        while (x > 0) {
          s += x % 10;
          x /= 10;
        }
        ans += s == j;
      }
    }
    out(ans);
    return 0;
  }
  mint::set_mod(K);
  vec<mint> a(N);
  rep(i, N) { a[i] = mint(10).pow(i) - 1; }
  auto dp = vec(ll, N, K);
  dp[0][0] = 1;
  rep(i, N - 1) {
    rep(k, K) {
      rep(j, 10) { dp[i + 1][(k + a[i] * j).val()] += dp[i][k]; }
    }
  }
  vi c(N);
  ll m = M;
  rep(i, N) {
    c[i] = m % 10;
    m /= 10;
  }
  ll ans = -1;
  mint s = 0;
  rrep(i, N) {
    rep(j, c[i]) { ans += dp[i][(s - j * a[i]).val()]; }
    s -= c[i] * a[i];
  }
  ans += s == 0;
  out(ans);
}
