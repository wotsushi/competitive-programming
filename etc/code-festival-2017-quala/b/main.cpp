#include "template.hpp"

int main() {
  ll(N, M, K);
  rep(i, N + 1) {
    rep(j, M + 1) {
      if (i * M + j * N - 2 * i * j == K) {
        out("Yes");
        return 0;
      }
    }
  }
  out("No");
}
