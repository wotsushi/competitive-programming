#include "template.hpp"

int main() {
  ll(N);
  ll ans;
  for (ll i = 1; i * i <= N; ++i) {
    ans = i * i;
  }
  out(ans);
}
