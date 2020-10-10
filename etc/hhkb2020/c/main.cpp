#include "template.hpp"

int main() {
  ll(N);
  vll(p, N);
  set<ll> S;
  ll j = 0;
  rep(i, N) {
    S.insert(p[i]);
    while (S.count(j)) {
      ++j;
    }
    out(j);
  }
}
