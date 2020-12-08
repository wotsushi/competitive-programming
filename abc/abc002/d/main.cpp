#include "template.hpp"

int main() {
  ll(N, M);
  vll(x, y, M);
  auto f = vec(bool, N, N);
  rep(i, M) {
    f[x[i] - 1][y[i] - 1] = true;
    f[y[i] - 1][x[i] - 1] = true;
  }
  rep(i, N) { f[i][i] = true; }
  ll ans = 1;
  rep(p, 1 << N) {
    bool ok = true;
    rep(i, N) {
      rep(j, N) {
        if ((p & (1 << i)) and (p & (1 << j))) {
          ok &= f[i][j];
        }
      }
    }
    if (ok) {
      chmax(ans, (ll)__builtin_popcount(p));
    }
  }
  out(ans);
}
