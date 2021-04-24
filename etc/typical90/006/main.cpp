#include "template.hpp"

int main() {
  ll(N, K);
  STR(S);
  auto C = vvi(26);
  rrep(i, N) { C[S[i] - 'a'].push_back(i); }
  string ans = "";
  ll j = 0;
  rrepi(k, K) {
    rep(i, 26) {
      while (not C[i].empty() and C[i].back() < j) {
        C[i].pop_back();
      }
      if (not C[i].empty() and C[i].back() + k <= N) {
        j = C[i].back() + 1;
        ans += 'a' + i;
        break;
      }
    }
  }
  out(ans);
}
