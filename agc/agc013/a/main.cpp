#include "template.hpp"

int main() {
  ll(N);
  vll(A, N);
  ll p = 0;
  ll ans = 1;
  rep(i, N - 1) {
    ll d = A[i + 1] - A[i];
    if (p == 0) {
      p = d;
    } else if (p * d < 0) {
      ++ans;
      p = 0;
    }
  }
  out(ans);
}
