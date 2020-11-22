#include "template.hpp"

int main() {
  ll(S, P);
  for (ll N = 1; N * N <= P; ++N) {
    if (P % N == 0) {
      ll M = P / N;
      if (N + M == S) {
        out("Yes");
        return 0;
      }
    }
  }
  out("No");
}
