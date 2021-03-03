#include "template.hpp"

int main() {
  ll(N, M);
  vll(A, B, M);
  ll(K);
  vll(C, D, K);
  ll ans = 0;
  rep(p, 1 << K) {
    vb b(N + 1);
    rep(i, K) {
      if ((p >> i) & 1) {
        b[C[i]] = true;
      } else {
        b[D[i]] = true;
      }
    }
    ll c = 0;
    rep(i, M) { c += b[A[i]] and b[B[i]]; }
    chmax(ans, c);
  }
  out(ans);
}
