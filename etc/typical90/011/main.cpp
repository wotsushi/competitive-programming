#include "template.hpp"

int main() {
  ll(N);
  vll(D, C, S, N);
  auto T = vec(iii, N);
  rep(i, N) { T[i] = {D[i], C[i], S[i]}; }
  SORT(T);
  ll M = get<0>(T[N - 1]);
  vi dp(M + 1);
  for (auto [d, c, s] : T) {
    rrepi(i, c, d) { chmax(dp[i], dp[i - c] + s); }
  }
  ll ans = *max_element(ALL(dp));
  out(ans);
}
