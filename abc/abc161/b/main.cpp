#include "template.hpp"

int main() {
  ll(N, M);
  vll(A, N);
  RSORT(A);
  ll s = 0;
  each(a, A) { s += a; }
  yes(4 * M * A[M - 1] >= s);
}
