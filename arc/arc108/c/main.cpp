#include "graph.hpp"
#include "template.hpp"

int main() {
  ll(N, M);
  graph<ll> G(N, M, true);
  cin >> G;
  vi ans(N + 1);
  auto f = def([&](auto&& f, ll i) -> void {
    for (auto [j, c] : G[i]) {
      if (ans[j] == 0) {
        if (ans[i] == c) {
          ans[j] = c % N + 1;
        } else {
          ans[j] = c;
        }
        f(j);
      }
    }
  });
  ans[1] = 1;
  f(1);
  repi(i, N) { out(ans[i]); }
}
