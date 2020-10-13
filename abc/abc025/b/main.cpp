#include "template.hpp"

int main() {
  ll(N, A, B);
  vs s(N);
  vi d(N);
  rep(i, N) { cin >> s[i] >> d[i]; }
  ll ans = 0;
  rep(i, N) {
    if (s[i] == "East") {
      ans += clamp(d[i], A, B);
    } else {
      ans -= clamp(d[i], A, B);
    }
  }
  if (ans > 0) {
    cout << "East" << ' ' << ans << endl;
  } else if (ans == 0) {
    out(0);
  } else {
    cout << "West" << ' ' << abs(ans) << endl;
  }
}
