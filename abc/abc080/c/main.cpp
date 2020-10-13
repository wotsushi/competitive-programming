#include "template.hpp"

int main() {
  ll(N);
  auto F = vec(ll, N, 10);
  rep(i, N) {
    rep(j, 10) { cin >> F[i][j]; }
  }
  auto P = vec(ll, N, 11);
  rep(i, N) {
    rep(j, 11) { cin >> P[i][j]; }
  }
  ll ans = -INF;
  rep(p, 1, 1 << 10) {
    ll s = 0;
    rep(i, N) {
      ll c = 0;
      rep(j, 10) {
        if (((p >> j) & 1) and F[i][j]) {
          ++c;
        }
      }
      s += P[i][c];
    }
    ch(max, ans, s);
  }
  out(ans)
}
