#include "template.hpp"

int main() {
  ll(N);
  vll(x, N);
  ll m = 0;
  double e = 0;
  ll c = 0;
  each(xi, x) {
    m += abs(xi);
    e += xi * xi;
    chmax(c, abs(xi));
  }
  out(m);
  fout(sqrt(e));
  out(c);
}
