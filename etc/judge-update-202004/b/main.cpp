#include "template.hpp"

int main() {
  ll(N);
  vi X(N);
  vec<char> C(N);
  rep(i, N) { cin >> X[i] >> C[i]; }
  rep(i, N) {
    if (C[i] == 'B') {
      X[i] += INF;
    }
  }
  SORT(X);
  each(x, X) {
    if (x < INF) {
      out(x);
    } else {
      out(x - INF);
    }
  }
}
