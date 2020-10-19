#include "graph.hpp"
#include "template.hpp"
#include "tree.hpp"

int main() {
  ll(N);
  graph<ll> G(N, N - 1, true);
  cin >> G;
  tree<ll> T(G);
  vi ans(N + 1);
  auto f = def([&](auto &&f, ll i) -> void {
    for (auto [j, w] : T[i]) {
      if (w & 1) {
        ans[j] = 1 - ans[i];
      } else {
        ans[j] = ans[i];
      }
      f(j);
    }
  });
  f(1);
  repi(i, N) { out(ans[i]); }
}
