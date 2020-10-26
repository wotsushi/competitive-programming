#include "comb.hpp"
#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(N);
  vll(T, N);
  ll opt = 0;
  ll s = 0;
  mint ans = 1;
  ll c = 0;
  comb<mint> comb(N);
  SORT(T);
  rep(i, N) {
    s += T[i];
    opt += s;
    if (i > 0 and T[i] != T[i - 1]) {
      ans *= comb.p(c, c);
      c = 1;
    } else {
      ++c;
    }
  }
  ans *= comb.p(c, c);
  out(opt);
  out(ans);
}
