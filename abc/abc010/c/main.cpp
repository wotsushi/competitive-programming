#include "template.hpp"

const double EPS = 1e-12;

int main() {
  ll(txa, tya, txb, tyb);
  ll(T, V);
  ll(n);
  vll(x, y, n);
  rep(i, n) {
    double d1 = sqrt(pow(x[i] - txa, 2) + pow(y[i] - tya, 2));
    double d2 = sqrt(pow(x[i] - txb, 2) + pow(y[i] - tyb, 2));
    if (d1 + d2 < V * T + EPS) {
      out("YES");
      return 0;
    }
  }
  out("NO");
}
