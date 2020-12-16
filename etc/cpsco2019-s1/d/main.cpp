#include "template.hpp"

using mint = modint1000000007;

int main() {
  ll(N);
  mint ans = 2 * mint(5).pow(N - 1) + 6 * mint(5).pow(N - 1);
  out(ans);
}
