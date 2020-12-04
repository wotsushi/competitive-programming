#include "template.hpp"

int main() {
  ll(N);
  vll(s, t, N);
  vii e;
  rep(i, N) {
    e.push_back({s[i], -1});
    e.push_back({t[i], 1});
  }
  SORT(e);
  ll p = 0;
  ll ans = 0;
  rep(i, 2 * N) {
    auto [_, y] = e[i];
    if (p == 0 and y == -1) {
      ++ans;
    }
    p -= y;
  }
  out(ans);
}
