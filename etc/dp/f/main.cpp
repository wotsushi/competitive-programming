#include "template.hpp"

int main() {
  STR(s);
  STR(t);
  ll N = s.size();
  ll M = t.size();
  auto dp = vec(ll, N + 1, M + 1);
  repi(i, N) {
    repi(j, M) {
      dp[i][j] = max({dp[i - 1][j], dp[i][j - 1],
                      dp[i - 1][j - 1] + (s[i - 1] == t[j - 1])});
    }
  }
  string ans = "";
  ll i = N;
  ll j = M;
  while (i > 0 and j > 0) {
    if (s[i - 1] == t[j - 1]) {
      ans = s[i - 1] + ans;
      --i;
      --j;
    } else if (dp[i][j] == dp[i - 1][j]) {
      --i;
    } else {
      --j;
    }
  }
  out(ans);
}
