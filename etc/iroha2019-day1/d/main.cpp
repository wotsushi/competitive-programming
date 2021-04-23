#include "template.hpp"

int main() {
  ll(N, X, Y);
  vll(A, N);
  RSORT(A);
  rep(i, N / 2) {
    X += A[2 * i];
    Y += A[2 * i + 1];
  }
  string ans;
  if (X > Y) {
    ans = "Takahashi";
  } else if (X < Y) {
    ans = "Aoki";
  } else {
    ans = "Draw";
  }
  out(ans);
}
