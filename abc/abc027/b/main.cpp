#include "template.hpp"

int main() {
  ll(N);
  vll(a, N);
  ll s = 0;
  each(x, a) { s += x; }
  if (s % N > 0) {
    out(-1);
    return 0;
  }
  ll acc = 0;
  ll m = 0;
  ll ans = 0;
  each(x, a) {
    acc += x;
    ++m;
    if (acc * N == s * m) {
      acc = 0;
      m = 0;
    } else {
      ++ans;
    }
  }
  out(ans);
}
