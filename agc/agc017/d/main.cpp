#include "graph.hpp"
#include "template.hpp"
#include "tree.hpp"

tree<ll> T;

ll f(ll i) {
  ll res = 0;
  for (auto [j, _] : T[i]) {
    res ^= f(j);
  }
  return res + 1;
}

int main() {
  ll(N);
  graph<ll> G(N, N - 1);
  cin >> G;
  T = tree<ll>(G);
  yes(f(1) > 1, "Alice", "Bob");
}
