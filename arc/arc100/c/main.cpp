#include "template.hpp"

int main() {
  ll(N);
  vll(A, N);
  rep(i, N) { A[i] -= i + 1; }
  SORT(A);
  ll b = A[N / 2];
  ll ans = 0;
  each(a, A) { ans += abs(a - b); }
  out(ans);
}
