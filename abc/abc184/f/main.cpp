#include "template.hpp"

int main() {
  ll(N, T);
  vll(A, N);
  vi S = {0};
  ll M = N / 2;
  rep(i, 1 << M) {
    ll s = 0;
    rep(j, M) {
      if ((i >> j) & 1) {
        s += A[j];
      }
    }
    S.push_back(s);
  }
  S.push_back(INF);
  SORT(S);
  ll L = N - M;
  ll ans = 0;
  rep(i, 1 << L) {
    ll s = 0;
    rep(j, L) {
      if ((i >> j) & 1) {
        s += A[M + j];
      }
    }
    s += *(upper_bound(ALL(S), T - s) - 1);
    if (s <= T) {
      chmax(ans, s);
    }
  }
  out(ans);
}
