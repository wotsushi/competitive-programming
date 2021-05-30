#include "template.hpp"

int main() {
  ll(N, Q);
  vll(A, N);
  vll(T, x, y, Q);
  ll b = 0;
  rep(i, Q) {
    --x[i];
    --y[i];
    if (T[i] == 1) {
      swap(A[(x[i] - b + N) % N], A[(y[i] - b + N) % N]);
    }
    if (T[i] == 2) {
      b = (b + 1) % N;
    }
    if (T[i] == 3) {
      out(A[(x[i] - b + N) % N]);
    }
  }
}
