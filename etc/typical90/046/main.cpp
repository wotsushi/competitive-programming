#include "template.hpp"

const int M = 46;

int main() {
  ll(N);
  vll(A, N);
  vll(B, N);
  vll(C, N);
  vi X(M), Y(M), Z(M);
  each(a, A) { ++X[a % M]; }
  each(b, B) { ++Y[b % M]; }
  each(c, C) { ++Z[c % M]; }
  ll ans = 0;
  rep(i, M) {
    rep(j, M) {
      rep(k, M) {
        if ((i + j + k) % M == 0) {
          ans += X[i] * Y[j] * Z[k];
        }
      }
    }
  }
  out(ans);
}
