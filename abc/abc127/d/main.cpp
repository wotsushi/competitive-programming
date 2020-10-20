#include "template.hpp"

int main() {
  ll(N, M);
  vll(A, N);
  vll(B, C, M);
  vi X;
  each(a, A) { X.push_back(a); }
  vii P(M);
  rep(i, M) { P[i] = {C[i], B[i]}; }
  RSORT(P);
  ll n = N;
  for (auto [c, b] : P) {
    while (n > 0 and b > 0) {
      X.push_back(c);
      --n;
      --b;
    }
  }
  RSORT(X);
  ll ans = 0;
  rep(i, N) { ans += X[i]; }
  out(ans);
}
