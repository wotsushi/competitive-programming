#include "template.hpp"

using mint = modint1000000007;

int main() {
  ll(N);
  STR(S);
  vec<mint> dp(8);
  dp[0] = 1;
  string a = "atcoder";
  each(s, S) {
    ll i = a.find(s);
    if (i == string::npos) {
      continue;
    }
    dp[i + 1] += dp[i];
  }
  out(dp[7]);
}
