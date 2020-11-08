#include "template.hpp"
using mint = modint998244353;

int main() {
  ll(N, K);
  auto used = vec(bool, N + 1, N + 1);
  auto dp = vec(mint, N + 1, N + 1);
  auto f = def([&](auto &&f, ll n, ll k) -> mint {
    if (used[n][k]) {
      return dp[n][k];
    }
    used[n][k] = true;
    if (k == 0 or n < k) {
      dp[n][k] = 0;
      return dp[n][k];
    }
    if (n == k) {
      dp[n][k] = 1;
      return dp[n][k];
    }
    if (2 * k > n) {
      dp[n][k] = f(n - 1, k - 1);
      return dp[n][k];
    }
    dp[n][k] = f(n - 1, k - 1) + f(n, 2 * k);
    return dp[n][k];
  });
  mint ans = f(N, K);
  out(ans);
}
