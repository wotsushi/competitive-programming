#include "template.hpp"

int main() {
  ll(Q);
  vll(A, B, C, Q);
  rep(i, Q) {
    A[i] &= 1;
    ll r = 100 * A[i] - 10 * min(B[i], 10 * A[i]);
    B[i] -= min(B[i], 10 * A[i]);
    B[i] &= 1;
    r += 10 * B[i];
    yes(C[i] >= r and C[i] % 2 == 0);
  }
}
