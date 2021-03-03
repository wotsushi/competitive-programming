#include "template.hpp"

int main() {
  ll(N, S, D);
  vll(X, Y, N);
  bool ok = false;
  rep(i, N) { ok |= not(X[i] >= S or Y[i] <= D); }
  yes(ok);
}
