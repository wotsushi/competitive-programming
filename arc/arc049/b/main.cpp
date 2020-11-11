#include "template.hpp"

int main() {
  ll(N);
  vll(x, y, c, N);
  double ok = INF;
  double ng = 0;
  rep(_, 100) {
    double mid = (ok + ng) / 2;
    double l = -INF;
    double r = INF;
    double u = INF;
    double d = -INF;
    rep(i, N) {
      chmax(l, x[i] - mid / c[i]);
      chmin(r, x[i] + mid / c[i]);
      chmin(u, y[i] + mid / c[i]);
      chmax(d, y[i] - mid / c[i]);
    }
    if (l <= r and d <= u) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  fout(ok);
}
