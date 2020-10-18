#include "template.hpp"

int main() {
  ll(N);
  ll ans = 0;
  repi(A, N) { ans += (N - 1) / A; }
  out(ans);
}
