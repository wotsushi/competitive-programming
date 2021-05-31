#include "template.hpp"

int main() {
  ll(N, K);
  ll ans = 0;
  repi(i, N) {
    repi(j, K) { ans += 100 * i + j; }
  }
  out(ans);
}
