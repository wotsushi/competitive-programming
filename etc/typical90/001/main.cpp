#include "template.hpp"

int main() {
  ll(N, L);
  ll(K);
  vll(A, N);
  A.insert(A.begin(), 0);
  A.push_back(L);
  vi D(N + 1);
  rep(i, N + 1) { D[i] = A[i + 1] - A[i]; }
  ll ok = 1;
  ll ng = INF;
  while (ng - ok > 1) {
    ll mid = (ng + ok) / 2;
    ll c = 0;
    ll s = 0;
    each(d, D) {
      s += d;
      if (s >= mid) {
        ++c;
        s = 0;
      }
    }
    if (c > K) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  ll ans = ok;
  out(ans);
}
