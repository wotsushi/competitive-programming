#include "template.hpp"

int main() {
  ll(N, K);
  vll(A, B, N);
  vi P;
  rep(i, N) {
    P.push_back(B[i]);
    P.push_back(A[i] - B[i]);
  }
  RSORT(P);
  ll ans = 0;
  rep(i, K) { ans += P[i]; }
  out(ans);
}
