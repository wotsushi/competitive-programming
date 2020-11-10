#include "template.hpp"

int main() {
  ll(N);
  vll(X, N);
  vi Y = X;
  SORT(Y);
  rep(i, N) { out(Y[N / 2 - (X[i] >= Y[N / 2])]); }
}
