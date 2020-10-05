#include "template.hpp"

int main() {
  ll(N);
  vll(A, B, N);
  vi X(2 * N);
  rep(i, N) {
    if (A[i] > 0 and B[i] > 0 and A[i] >= B[i]) {
      out("No");
      return 0;
    }
    if (A[i] > 0) {
      if (X[A[i] - 1] == 0) {
        X[A[i] - 1] = i + 1;
      } else {
        out("No");
        return 0;
      }
    }
    if (B[i] > 0) {
      if (X[B[i] - 1] == 0) {
        X[B[i] - 1] = -(i + 1);
      } else {
        out("No");
        return 0;
      }
    }
  }
  vec<bool> dp(N + 1);
  dp[0] = true;
  repi(i, N) {
    rep(j, i) {
      ll d = i - j;
      bool ok = true;
      rep(k, d) {
        ll l = 2 * j + k;
        ll r = 2 * j + k + d;
        ll xl = X[l];
        ll xr = X[r];
        ok &= (xl == -xr) or (xl > 0 and xr == 0 and B[xl - 1] == -1) or
              (xr < 0 and xl == 0 and A[-xr - 1] == -1);
      }
      dp[i] = dp[i] or (dp[j] and ok);
    }
  }
  yes(dp[N]);
}
