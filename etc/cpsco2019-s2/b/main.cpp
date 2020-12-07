#include "template.hpp"

int main() {
  ll(N);
  vec<char> c(N);
  vi a(N);
  rep(i, N) {
    cin >> c[i];
    cin >> a[i];
  }
  ll ans = 0;
  rep(i, N) {
    if (c[i] == '+') {
      ans += a[i];
    }
  }
  rep(i, N) {
    if (c[i] == '*') {
      ans *= max(1LL, a[i]);
    }
  }
  out(ans);
}
