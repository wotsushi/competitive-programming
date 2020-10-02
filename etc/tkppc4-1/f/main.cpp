#include "template.hpp"

int main() {
  ll(N, M);
  vvi A = vec(ll, N, vi(M));
  vvi B = vec(ll, N, vi(M));
  rep(i, N) {
    rep(j, M) { cin >> A[i][j]; }
  }
  rep(i, N) {
    rep(j, M) { cin >> B[i][j]; }
  }
  ll ans = 0;
  rep(i, N) {
    ll x = INF;
    rep(j, M) {
      ch(min, x, ((A[i][j] - ans) % A[i][j] + A[i][j]) % A[i][j] + B[i][j]);
    }
    ans += x;
  }
  out(ans);
}
