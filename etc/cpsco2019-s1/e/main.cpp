#include "template.hpp"

int main() {
  ll(N, Q);
  vll(A, N);
  vll(L, R, X, Q);
  set<ll> S;
  each(a, A) {
    if (S.count(a)) {
      S.erase(a);
    } else {
      S.insert(a);
    }
  }
  rep(i, Q) {
    ll ans = 0;
    ll c = 0;
    vi D;
    for (auto j = S.lower_bound(L[i]); j != S.end() and *j <= R[i]; ++j) {
      ans ^= *j;
      D.push_back(*j);
      ++c;
    }
    each(d, D) { S.erase(d); }
    out(ans);
    if (c & 1) {
      if (S.count(X[i])) {
        S.erase(X[i]);
      } else {
        S.insert(X[i]);
      }
    }
  }
}
