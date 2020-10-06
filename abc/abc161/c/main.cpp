#include "template.hpp"

int main() {
  ll(N, K);
  ll m = N % K;
  out(min({m, abs(m - K)}));
}
