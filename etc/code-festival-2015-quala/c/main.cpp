#include "template.hpp"

int main() {
  ll(N, T);
  vll(A, B, N);
  ll s = 0;
  vi D(N);
  rep(i, N) {
    s += A[i];
    D.push_back(A[i] - B[i]);
  }
  RSORT(D);
  rep(i, N) {
    if (s <= T) {
      out(i);
      return 0;
    }
    s -= D[i];
  }
  if (s <= T) {
    out(N);
  } else {
    out(-1);
  }
}
