#include "template.hpp"

int main() {
  ll(x_a, y_a);
  ll(x_b, y_b);
  ll(x_c, y_c);
  double ans = abs((x_b - x_a) * (y_c - y_a) - (x_c - x_a) * (y_b - y_a)) / 2.0;
  fout(ans);
}
