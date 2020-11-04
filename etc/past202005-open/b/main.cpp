#include "template.hpp"

int main() {
  ll(N, M, Q);
  auto solved = vec(bool, N + 1, M + 1);
  vi p(M + 1, N);
  rep(_, Q) {
    ll(t);
    if (t == 1) {
      ll(n);
      ll ans = 0;
      repi(i, M) { ans += solved[n][i] * p[i]; }
      out(ans);
    } else {
      ll(n, m);
      solved[n][m] = true;
      --p[m];
    }
  }
}
