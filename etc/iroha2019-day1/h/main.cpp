#include "template.hpp"

int main() {
  ll(N);
  if (N < 10) {
    out(10 + (N - 1));
    return 0;
  }
  ll f = 0;
  ll X = N;
  while (X > 0) {
    f += X % 10;
    X /= 10;
  }
  ll ans = 0;
  ll k = 1;
  while (f > 0) {
    ll x = min(f, 9LL);
    ans += k * x;
    k *= 10;
    f -= x;
  }
  if (ans == N) {
    k /= 10;
    if (ans / k == 9) {
      ans += k * 10 - k;
    } else {
      ans += k - (k / 10);
    }
  }
  out(ans);
}
