#include "template.hpp"

int main() {
  ll(N, K);
  vll(a, N);
  a.push_back(0);
  vi B;
  ll b = 1;
  repi(i, 1, N) {
    if (a[i] == a[i - 1]) {
      ++b;
    } else {
      B.push_back(b);
      b = 1;
    }
  }
  ll ok = N;
  ll ng = 0;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    ll k = 0;
    each(b, B) { k += b / (mid + 1); }
    if (k <= K) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  out(ok);
}
