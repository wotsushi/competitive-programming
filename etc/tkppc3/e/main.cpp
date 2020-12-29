#include "template.hpp"

int main() {
  ll(n);
  double ans = (n + 1) / 2.0;
  double p = 1;
  double x = 0;
  repi(i, n) {
    x += p * i * i / n;
    p *= 1. * (n - i) / n;
  }
  ans *= x;
  fout(ans);
}
