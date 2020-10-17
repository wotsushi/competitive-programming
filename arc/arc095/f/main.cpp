#include "graph.hpp"
#include "template.hpp"
#include "tree.hpp"

int main() {
  ll(n);
  graph<ll> G(n, n - 1);
  cin >> G;
  graph<ll> H(n);
  vi L(n + 1);
  repi(i, n) {
    if (G[i].size() == 1) {
      continue;
    }
    for (auto [j, _] : G[i]) {
      if (G[j].size() == 1) {
        ++L[i];
      } else if (i < j) {
        H.add(i, j);
      }
    }
  }
  ll a = 0;
  ll b = 0;
  repi(i, n) {
    if (H[i].size() >= 3) {
      out(-1);
      return 0;
    }
    if (H[i].size() == 1) {
      if (a == 0) {
        a = i;
      } else {
        b = i;
      }
    }
  }
  if (a == 0) {
    vi ans{1};
    repi(i, 3, n) { ans.push_back(i); }
    ans.push_back(2);
    swap(ans[n - 2], ans[n - 1]);
    jout(ALL(ans)) << endl;
    return 0;
  }
  auto f = [&](ll s, ll t) {
    vi res{1};
    ll x = 3;
    rep(_, L[s] - 1) { res.push_back(x++); }
    res.push_back(2);
    tree<ll> T(H, s);
    ll i = s;
    while (i != t) {
      i = T[i][0].first;
      repi(k, L[i]) { res.push_back(x + k); }
      res.push_back(x);
      x += L[i] + 1;
    }
    swap(res[n - 2], res[n - 1]);
    return res;
  };
  vi ans = min(f(a, b), f(b, a));
  jout(ALL(ans)) << endl;
}
