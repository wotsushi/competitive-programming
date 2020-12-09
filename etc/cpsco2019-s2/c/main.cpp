#include "template.hpp"

int main() {
  ll(N, K);
  STR(S);
  vi B(N + 1);
  ll l = 0;
  each(c, S) {
    if (c == '(') {
      ++l;
    } else {
      ++B[l];
      --l;
    }
  }
  ll ans = 0;
  rrep(i, N) {
    ans += i * min(B[i] + B[i + 1], K);
    K -= min(B[i] + B[i + 1], K);
  }
  out(ans);
}
