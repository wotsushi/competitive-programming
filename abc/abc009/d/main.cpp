#include "matrix.hpp"
#include "template.hpp"

int main() {
  ll(K, M);
  vll(A, K);
  vll(C, K);
  ll ans;
  if (M <= K) {
    ans = A[M - 1];
  } else {
    ans = 0;
    matrix<ll> X(K);
    rep(i, 1, K) { X[i][i - 1] = 1; }
    rep(k, 32) {
      rep(i, K) { X[0][i] = (C[i] >> k) & 1; }
      auto Y = X.pow(M - K);
      ll a = 0;
      rep(i, K) { a += (Y[0][i] & 1) * ((A[K - 1 - i] >> k) & 1); }
      ans += (a & 1) * (1LL << k);
    }
  }
  out(ans);
}
