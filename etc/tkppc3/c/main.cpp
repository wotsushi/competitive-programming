#include "template.hpp"

int main() {
  ll(N, P);
  vll(A, N);
  ll j = 0;
  ll p = 1;
  rep(i, N) {
    for (; j < N and p < P; ++j) {
      p *= A[j];
    }
    if (p == P) {
      out("Yay!");
      return 0;
    }
    p /= A[i];
  }
  out(":(")
}
