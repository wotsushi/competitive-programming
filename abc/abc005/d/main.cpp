#include "template.hpp"

int main() {
  ll(N);
  vvll(D, N);
  ll(Q);
  vll(P, Q);
  auto s = vec(ll, N + 1, N + 1);
  repi(i, N) {
    repi(j, N) {
      s[i][j] = D[i - 1][j - 1] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
    }
  }
  each(p, P) {
    ll ans = 0;
    repi(i, N) {
      repi(j, N) {
        repi(k, i, N) {
          ll h = p / (k - i + 1);
          if (h == 0) {
            continue;
          }
          ll l = min(N, j + h - 1);
          chmax(ans, s[k][l] - s[i - 1][l] - s[k][j - 1] + s[i - 1][j - 1]);
        }
      }
    }
    out(ans);
  }
}
