#include "template.hpp"

int main() {
  ll(N);
  vin(string, S, N);
  ll d = 0;
  rep(i, N) {
    rep(j, N) {
      d += S[i][j] == 'R';
      d -= S[i][j] == 'B';
    }
  }
  string ans;
  if (d > 0) {
    ans = "TAKAHASHI";
  } else if (d == 0) {
    ans = "DRAW";
  } else {
    ans = "AOKI";
  }
  out(ans);
}
