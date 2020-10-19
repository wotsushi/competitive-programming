#include "template.hpp"

int main() {
  ll(N);
  vll(A, N);
  vll(B, N);
  vi C(N / 2), D(N / 2);
  ll ans = 0;
  rep(i, N / 2) {
    C[i] = B[2 * i] - A[2 * i];
    D[i] = B[2 * i + 1] - A[2 * i + 1];
    ans += A[2 * i] + A[2 * i + 1];
  }
  RSORT(C);
  RSORT(D);
  rep(i, N / 2) { ans += max(0LL, C[i] + D[i]); }
  out(ans);
}
