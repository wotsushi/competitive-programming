#include "template.hpp"

int main() {
  ll(M, N);
  ll ans = M - (M / N) * (N - 1);
  out(ans);
}
