#include "template.hpp"

int main() {
  ll(x, y);
  ll(N);
  vll(X, Y, N);
  X.push_back(X[0]);
  Y.push_back(Y[0]);
  double ans = INF;
  rep(i, N) {
    complex<double> ap{x - X[i], y - Y[i]},
        ab{X[i + 1] - X[i], Y[i + 1] - Y[i]};
    chmin(ans, abs(ap.real() * ab.imag() - ap.imag() * ab.real()) / abs(ab));
  }
  fout(ans);
}
