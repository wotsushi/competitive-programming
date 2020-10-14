#include "template.hpp"

int main() {
  ll(N, Q);
  vll(A, N);
  vll(S, Q);
  vi acc(N + 1);
  rep(i, N) { acc[i + 1] = gcd(acc[i], A[i]); }
  rep(i, Q) {
    ll g = gcd(S[i], acc[N]);
    if (g > 1) {
      out(g);
    } else {
      ll ok = N;
      ll ng = 0;
      while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if (gcd(S[i], acc[mid]) == 1) {
          ok = mid;
        } else {
          ng = mid;
        }
      }
      out(ok);
    }
  }
}
