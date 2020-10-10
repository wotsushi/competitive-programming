#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(H, W);
  vin(string, S, H);
  vvi x = vec(ll, H, W);
  vvi y = vec(ll, H, W);
  ll m = 0;
  rep(i, H) {
    rep(j, W) {
      m += S[i][j] == '.';
      if (S[i][j] == '.' and x[i][j] == 0) {
        ll c = 0;
        rep(k, j, W) {
          if (S[i][k] == '.') {
            ++c;
          } else {
            break;
          }
        }
        rep(k, j, W) {
          if (S[i][k] == '.') {
            x[i][k] = c;
          } else {
            break;
          }
        }
      }
      if (S[i][j] == '.' and y[i][j] == 0) {
        ll c = 0;
        rep(k, i, H) {
          if (S[k][j] == '.') {
            ++c;
          } else {
            break;
          }
        }
        rep(k, i, H) {
          if (S[k][j] == '.') {
            y[k][j] = c;
          } else {
            break;
          }
        }
      }
    }
  }
  mint ans = 0;
  rep(i, H) {
    rep(j, W) {
      if (S[i][j] == '.') {
        ll c = x[i][j] + y[i][j] - 1;
        ans += (mint(2).pow(c) - 1) * mint(2).pow(m - c);
      }
    }
  }
  out(ans.val());
}
