#include "template.hpp"
using mint = modint1000000007;

int main() {
  STR(S);
  ll Q = 0;
  auto dp = vec(mint, 4, 4);
  dp[0][0] = 1;
  each(c, S) {
    if (c == 'C') {
      rep(j, 3) { dp[3][j] += dp[2][j]; }
    }
    if (c == 'B') {
      rep(j, 2) { dp[2][j] += dp[1][j]; }
    }
    if (c == 'A') {
      ++dp[1][0];
    }
    if (c == '?') {
      ++Q;
      rrepi(i, 3) {
        repi(j, i) { dp[i][j] += dp[i - 1][j - 1]; }
      }
    }
  }
  mint ans = 0;
  rep(j, 4) { ans += dp[3][j] * mint(3).pow(max(0LL, Q - j)); }
  out(ans);
}
