#include "template.hpp"

int main() {
  ll(N);
  vll(A, N);
  ll(Q);
  vll(B, Q);
  SORT(A);
  each(b, B) {
    ll i = lower_bound(ALL(A), b) - A.begin();
    chmin(i, N - 1);
    ll j = max(0LL, i - 1);
    ll ans = min(abs(A[i] - b), abs(A[j] - b));
    out(ans);
  }
}
