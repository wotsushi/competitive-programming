#include "template.hpp"

int main() {
  ll(N);
  vll(A, N);
  RSORT(A);
  rep(i, N) {
    if (A[i] < A[0]) {
      out(A[i]);
      break;
    }
  }
}
