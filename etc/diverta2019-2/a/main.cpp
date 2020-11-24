#include "template.hpp"

int main() {
  ll(N, K);
  ll ans;
  if (K == 1) {
    ans = 0;
  } else {
    ans = N - K;
  }
  out(ans);
}
