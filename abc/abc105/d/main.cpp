#include "template.hpp"

int main() {
  ll(N, M);
  vll(A, N);
  map<ll, ll> dp{{0, 1}};
  ll ans = 0;
  ll s = 0;
  each(a, A) {
    s = (s + a) % M;
    ans += dp[s];
    ++dp[s];
  }
  out(ans);
}
