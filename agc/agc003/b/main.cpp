#include "template.hpp"

int main() {
  ll(N);
  vll(A, N);
  ll ans = 0;
  rep(i, N) {
    ans += A[i] / 2;
    A[i] %= 2;
    if (i < N - 1 and A[i] == 1 and A[i + 1] >= 1) {
      ++ans;
      --A[i + 1];
    }
  }
  out(ans);
}
