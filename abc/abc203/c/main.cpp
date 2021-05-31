#include "template.hpp"

int main() {
  ll(N, K);
  vll(A, B, N);
  vii P(N);
  rep(i, N) { P[i] = {A[i], B[i]}; }
  SORT(P);
  for (auto [a, b] : P) {
    if (K < a) {
      break;
    }
    K += b;
  }
  out(K);
}
