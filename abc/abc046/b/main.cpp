#include "template.hpp"

int main() {
  ll(N, K);
  ll ans = K;
  rep(_, N - 1) { ans *= K - 1; }
  out(ans);
}
