#include "grid.hpp"
#include "template.hpp"

int main() {
  ll(H, W, T);
  vin(string, s, H);
  ll s_i, s_j;
  rep(i, H) {
    rep(j, W) {
      if (s[i][j] == 'S') {
        s_i = i;
        s_j = j;
      }
    }
  }
  ll ok = 1;
  ll ng = T;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    auto used = vec(bool, H, W);
    pq<iii> q;
    q.push({0, s_i, s_j});
    used[s_i][s_j] = true;
    while (not q.empty()) {
      auto [t, i, j] = q.top();
      q.pop();
      if (s[i][j] == 'G') {
        if (t <= T) {
          ok = mid;
        } else {
          ng = mid;
        }
        break;
      }
      way4(i, j, H, W, [&](ll u, ll v) {
        if (used[u][v]) {
          return;
        }
        ll t2;
        if (s[u][v] == '#') {
          t2 = t + mid;
        } else {
          t2 = t + 1;
        }
        q.push({t2, u, v});
        used[u][v] = true;
      });
    }
  }
  out(ok);
}
