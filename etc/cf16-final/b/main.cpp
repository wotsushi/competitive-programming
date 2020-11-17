#include "template.hpp"

int main() {
  ll(N);
  ll k;
  repi(i, N) {
    if (i * (i + 1) / 2 >= N) {
      k = i;
      break;
    }
  }
  rrepi(i, k) {
    if (N >= i) {
      N -= i;
      out(i);
    }
  }
}
