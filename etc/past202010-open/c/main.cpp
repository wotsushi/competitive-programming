#include "grid.hpp"
#include "template.hpp"

int main() {
  ll(N, M);
  vin(string, s, N);
  vs ans(N, string(M, '0'));
  rep(i, N) {
    rep(j, M) {
      ans[i][j] += s[i][j] == '#';
      way8(i, j, N, M, [&](ll u, ll v) { ans[i][j] += s[u][v] == '#'; });
    }
  }
  each(ans_i, ans) { out(ans_i); }
}
