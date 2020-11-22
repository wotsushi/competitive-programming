#include "template.hpp"

int main() {
  ll(N);
  vll(x, y, N);
  double ans = 0;
  rep(i, N) {
    rep(j, N) { chmax(ans, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2))); }
  }
  fout(ans);
}
