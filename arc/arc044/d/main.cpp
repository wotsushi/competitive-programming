#include "template.hpp"

int main() {
  ll(N);
  vll(A, N);
  vi B(N + 1);
  rep(i, N) { B[A[i] - 1] = i + 1; }
  string ans(N, 'A');
  char c = 'A';
  rep(i, 1, N) {
    if (B[A[i]] < B[A[i - 1]]) {
      ++c;
      if (c > 'Z') {
        out(-1);
        return 0;
      }
    }
    ans[A[i] - 1] = c;
  }
  out(ans);
}
