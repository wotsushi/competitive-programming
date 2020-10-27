#include "template.hpp"

int main() {
  ll(N);
  vll(T, A, N);
  ll t = 1;
  ll a = 1;
  rep(i, N) {
    ll r = max((t + T[i] - 1) / T[i], (a + A[i] - 1) / A[i]);
    t = r * T[i];
    a = r * A[i];
  }
  ll ans = t + a;
  out(ans);
}
