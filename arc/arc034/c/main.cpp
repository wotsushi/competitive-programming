#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(A, B);
  map<ll, ll> p;
  repi(i, B + 1, A) {
    ll x = i;
    for (ll j = 2; j * j <= i; ++j) {
      while (x % j == 0) {
        x /= j;
        ++p[j];
      }
    }
    if (x > 1) {
      ++p[x];
    }
  }
  mint ans = 1;
  for (auto [_, k] : p) {
    ans *= (k + 1);
  }
  out(ans.val());
}
