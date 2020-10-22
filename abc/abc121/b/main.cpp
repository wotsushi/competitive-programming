#include "template.hpp"

int main() {
  ll(N, M, C);
  vll(B, M);
  auto A = vec(ll, N, M);
  rep(i, N) {
    rep(j, M) { cin >> A[i][j]; }
  }
  ll ans = 0;
  rep(i, N) {
    ll s = C;
    rep(j, M) { s += A[i][j] * B[j]; }
    ans += s > 0;
  }
  out(ans);
}
