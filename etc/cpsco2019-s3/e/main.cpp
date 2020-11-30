#include "template.hpp"

int main() {
  ll(N);
  vll(A, N);
  vi ans(N);
  rep(l, 30) {
    vi acc(N + 1);
    rep(k, N) { acc[k + 1] = acc[k] + ((A[k] >> l) & 1); }
    ll X = 0;
    rep(k, N) {
      X ^= (A[k] >> l) & 1;
      if (X == 0) {
        ans[k] += acc[k + 1] << l;
      } else {
        ans[k] += ((k + 1) - acc[k + 1]) << l;
      }
    }
  }
  each(ans_i, ans) { out(ans_i); }
}
