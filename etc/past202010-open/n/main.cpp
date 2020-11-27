#include "template.hpp"

const int N = 18;
const int M = 6;

int main() {
  vin(string, s, N);
  s.push_back(string(M, '0'));
  auto dp = vec(ll, N + 2, 1 << M, 1 << M);
  dp[0][0][0] = 1;
  rep(i, N + 1) {
    rep(x, 1 << M) {
      bool ok = true;
      rep(l, M) {
        ok &= ((x >> l) & 1) == 0 and s[i][l] != '1' or
              ((x >> l) & 1) == 1 and s[i][l] != '0';
      }
      if (not ok) {
        continue;
      }
      rep(j, 1 << M) {
        rep(k, 1 << M) {
          bool ok = true;
          rep(l, M) {
            ll s = ((j >> l) & 1) + ((k >> (l + 1)) & 1) + ((k >> l) & 1) +
                   ((x >> l) & 1);
            if (l >= 1) {
              s += (k >> (l - 1)) & 1;
            }
            ok &= ((((k >> l) & 1) == 0) and s <= 2) or
                  ((((k >> l) & 1) == 1) and s >= 3);
          }
          if (ok) {
            dp[i + 1][k][x] += dp[i][j][k];
          }
        }
      }
    }
  }
  ll ans = 0;
  rep(j, 1 << M) { ans += dp[N + 1][j][0]; }
  out(ans);
}
