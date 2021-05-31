#include "template.hpp"

int main() {
  ll(N, M);
  vll(X, Y, M);
  vii P(M);
  rep(i, M) { P[i] = {X[i], Y[i]}; }
  SORT(P);
  P.push_back({2 * N + 1, 0});
  set<ll> S{N}, B;
  rep(i, M) {
    B.insert(P[i].second);
    if (P[i].first == P[i + 1].first) {
      continue;
    }
    set<ll> D, A;
    for (auto b : B) {
      if (S.count(b) and (not S.count(b - 1)) and (not S.count(b + 1))) {
        D.insert(b);
      }
      if (S.count(b - 1) or S.count(b + 1)) {
        A.insert(b);
      }
    }
    for (auto d : D) {
      S.erase(d);
    }
    for (auto a : A) {
      S.insert(a);
    }
    B.clear();
  }
  ll ans = S.size();
  out(ans);
}
