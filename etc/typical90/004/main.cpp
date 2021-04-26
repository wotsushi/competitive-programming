#include "template.hpp"

int main() {
  ll(H, W);
  auto A = vec(ll, H, W);
  rep(i, H) {
    rep(j, W) { cin >> A[i][j]; }
  }
  vi R(H), C(W);
  rep(i, H) {
    rep(j, W) {
      R[i] += A[i][j];
      C[j] += A[i][j];
    }
  }
  auto B = vec(ll, H, W);
  rep(i, H) {
    rep(j, W) { B[i][j] = R[i] + C[j] - A[i][j]; }
  }
  rep(i, H) { jout(ALL(B[i])) << endl; }
}
