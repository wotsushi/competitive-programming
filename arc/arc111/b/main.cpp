#include "template.hpp"

const ll M = 4e5;

int main() {
  ll(N);
  vll(a, b, N);
  dsu dsu(M + 1);
  vb loop(M + 1);
  vb exist(M + 1);
  rep(i, N) {
    exist[a[i]] = true;
    exist[b[i]] = true;
    if (dsu.same(a[i], b[i])) {
      loop[dsu.leader(a[i])] = true;
    } else {
      bool l = loop[dsu.leader(a[i])] or loop[dsu.leader(b[i])];
      dsu.merge(a[i], b[i]);
      loop[dsu.leader(a[i])] = l;
    }
  }
  ll ans = 0;
  repi(i, M) {
    if (exist[i] and i == dsu.leader(i)) {
      ans += dsu.size(i);
      if (not loop[i]) {
        --ans;
      }
    }
  }
  out(ans);
}
