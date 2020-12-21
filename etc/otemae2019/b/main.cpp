#include "template.hpp"

int main() {
  ll(M, N, K);
  vll(x, N);
  ll ans = 1;
  repi(i, M) {
    vb used(K + 1);
    ll opt = 0;
    each(x_i, x) {
      ll d = abs(x_i - i);
      if (d == 0 or d <= K and not used[d]) {
        ++opt;
        used[d] = true;
      }
    }
    chmax(ans, opt);
  }
  out(ans);
}
