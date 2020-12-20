#include "grid.hpp"
#include "template.hpp"

int main() {
  ll(H, W, X);
  vin(string, s, H);
  ii start, goal;
  vii B;
  auto ok = vecv(bool, H, W, true);
  rep(i, H) {
    rep(j, W) {
      if (s[i][j] == 'S') {
        start = {i, j};
        ok[i][j] = false;
      }
      if (s[i][j] == 'G') {
        goal = {i, j};
      }
      if (s[i][j] == '@') {
        B.push_back({i, j});
        ok[i][j] = false;
      }
    }
  }
  queue<iii> q;
  for (auto [i, j] : B) {
    q.push({i, j, X});
  }
  while (not q.empty()) {
    auto [i, j, k] = q.front();
    q.pop();
    if (k == 0) {
      continue;
    }
    way4(i, j, H, W, [&](ll u, ll v) {
      if (s[u][v] != '#' and ok[u][v]) {
        ok[u][v] = false;
        q.push({u, v, k - 1});
      }
    });
  }
  q.push({start.first, start.second, 0});
  while (not q.empty()) {
    auto [i, j, k] = q.front();
    q.pop();
    if (ii{i, j} == goal) {
      out(k);
      return 0;
    }
    way4(i, j, H, W, [&](ll u, ll v) {
      if (s[u][v] != '#' and ok[u][v]) {
        q.push({u, v, k + 1});
        ok[u][v] = false;
      }
    });
  }
  out(-1);
}
