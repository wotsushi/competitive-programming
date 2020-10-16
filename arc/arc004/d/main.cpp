#include "comb.hpp"
#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(N, M);
  comb<mint> comb(M + 50);
  mint ans = mint(2).pow(M - 1);
  ll n = abs(N);
  for (ll i = 2; i * i <= n; ++i) {
    ll c = 0;
    while (n % i == 0) {
      ++c;
      n /= i;
    }
    ans *= comb.h(M, c);
  }
  if (n > 1) {
    ans *= M;
  }
  out(ans);
}
