#include "template.hpp"

int main() {
  ll(T);
  rep(_, T) {
    STR(S);
    if (S > "atcoder") {
      out(0);
      continue;
    }
    ll N = S.size();
    ll ans = -1;
    repi(i, N - 1) {
      if (S[i] != 'a') {
        if (S[i] > 't') {
          ans = max(1LL, i - 1);
        } else {
          ans = i;
        }
        break;
      }
    }
    out(ans);
  }
}
