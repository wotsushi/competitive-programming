#include "template.hpp"

int main() {
  ll(N, M);
  vll(a, N);
  RSORT(a);
  ll s = 0;
  ll ans;
  rep(i, N) {
    s += a[i];
    if (s >= M) {
      ans = i + 1;
      break;
    }
  }
  out(ans)
}
