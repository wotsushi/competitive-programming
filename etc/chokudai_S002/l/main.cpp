#include "compress.hpp"
#include "template.hpp"

int main() {
  ll(N);
  vll(A, B, N);
  vii P(N);
  rep(i, N) { P[i] = {min(A[i], B[i]), -max({A[i], B[i]})}; }
  SORT(P);
  vi Y(N);
  rep(i, N) { Y[i] = -P[i].second; }
  Y = compress(Y);
  vi dp(N, INF);
  rep(i, N) { *lower_bound(ALL(dp), Y[i]) = Y[i]; }
  rrep(i, N) {
    if (dp[i] < INF) {
      out(i + 1);
      break;
    }
  }
}
