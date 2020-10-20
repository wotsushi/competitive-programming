#include "template.hpp"

int main() {
  ll(N, K);
  vll(H, N);
  RSORT(H);
  ll ans = 0;
  rep(i, K, N) { ans += H[i]; }
  out(ans);
}
