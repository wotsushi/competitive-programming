#include "template.hpp"

int main() {
  ll(n);
  vll(a, n);
  ll ans = 0;
  each(x, a) {
    rrepi(i, x) {
      if (i % 3 != 2 and (i & 1)) {
        break;
      }
      ++ans;
    }
  }
  out(ans);
}
