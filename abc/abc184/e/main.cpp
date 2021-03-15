#include "grid.hpp"
#include "template.hpp"

int main() {
  ll(H, W);
  vin(string, a, H);
  ll s_i, s_j;
  auto T = vec(vec<ii>, 26);
  rep(i, H) {
    rep(j, W) {
      char c = a[i][j];
      if (c == 'S') {
        s_i = i;
        s_j = j;
      }
      if ('a' <= c and c <= 'z') {
        T[c - 'a'].push_back({i, j});
      }
    }
  }
  auto used = vec(bool, H, W);
  queue<iii> q;
  q.push({s_i, s_j, 0});
  used[s_i][s_j] = true;
  while (not q.empty()) {
    auto [i, j, c] = q.front();
    q.pop();
    if (a[i][j] == 'G') {
      out(c);
      return 0;
    }
    way4(i, j, H, W, [&](ll u, ll v) {
      if (a[u][v] != '#' and not used[u][v]) {
        used[u][v] = true;
        q.push({u, v, c + 1});
      }
    });
    if ('a' <= a[i][j] and a[i][j] <= 'z') {
      for (auto [u, v] : T[a[i][j] - 'a']) {
        if (not used[u][v]) {
          used[u][v] = true;
          q.push({u, v, c + 1});
        }
      }
      T[a[i][j] - 'a'].clear();
    }
  }
  out(-1);
}
