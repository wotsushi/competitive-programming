#include "template.hpp"

int main() {
  ll(R, B);
  ll(x, y);
  ll ok = 0;
  ll ng = INF;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    if (R >= mid and B >= mid and
        (R - mid) / (x - 1) + (B - mid) / (y - 1) >= mid) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  out(ok);
}
