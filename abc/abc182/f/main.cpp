#include "template.hpp"

int main() {
  ll(N, X);
  vll(A, N);
  vi x(N), y(N), a(N), b(N);
  x[0] = X;
  y[0] = X;
  a[0] = 1;
  rep(i, N - 1) {
    a[i + 1] = a[i];
    b[i + 1] = b[i];
    if (x[i] % A[i + 1] == 0) {
      x[i + 1] = x[i];
    } else {
      x[i + 1] = A[i + 1] * (x[i] / A[i + 1]);
      b[i + 1] += a[i];
    }
    if (y[i] % A[i + 1] == 0) {
      y[i + 1] = y[i];
    } else {
      y[i + 1] = A[i + 1] * (y[i] / A[i + 1] + 1);
      a[i + 1] += b[i];
    }
  }
  ll ans = a[N - 1] + b[N - 1];
  out(ans);
}
