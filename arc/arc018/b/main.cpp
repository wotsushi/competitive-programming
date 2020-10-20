#include "template.hpp"

int main() {
  ll(N);
  vll(x, y, N);
  ll ans = 0;
  rep(i, N) {
    rep(j, i + 1, N) {
      rep(k, j + 1, N) {
        ll S =
            abs((x[i] - x[k]) * (y[j] - y[k]) - (x[j] - x[k]) * (y[i] - y[k]));
        ans += S % 2 == 0 and S > 0;
      }
    }
  }
  out(ans);
}
