#include "template.hpp"

int main() {
  ll(H, W);
  vin(string, S, H);
  ll ans = 0;
  rep(i, H) {
    rep(j, W) {
      ans += j < W - 1 and S[i][j] == '.' and S[i][j + 1] == '.';
      ans += i < H - 1 and S[i][j] == '.' and S[i + 1][j] == '.';
    }
  }
  out(ans);
}
