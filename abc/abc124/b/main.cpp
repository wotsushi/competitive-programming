#include "template.hpp"

int main() {
  ll(N);
  vll(H, N);
  ll x = 0;
  ll ans = 0;
  each(h, H) {
    if (h >= x) {
      ++ans;
      x = h;
    }
  }
  out(ans);
}
