#include "matrix.hpp"
#include "template.hpp"
using mint = modint;

int main() {
  ll(N);
  vll(a, L, N);
  ll(B);
  mint::set_mod(B);
  mint ans = 0;
  ll d = 0;
  rrep(i, N) {
    ll k = to_string(a[i]).size();
    matrix<mint> X(vec2<mint>{vec<mint>{mint(10).pow(k), 1}, vec<mint>{0, 1}});
    ans += X.pow(L[i])[0][1] * a[i] * mint(10).pow(d);
    d += k * L[i];
  }
  out(ans.val());
}
