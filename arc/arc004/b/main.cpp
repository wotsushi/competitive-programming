#include "template.hpp"

int main() {
  ll(N);
  vll(d, N);
  ll ans_max = 0;
  each(d_i, d) { ans_max += d_i; }
  ll m = *max_element(ALL(d));
  ll ans_min = max(0LL, 2 * *max_element(ALL(d)) - ans_max);
  out(ans_max);
  out(ans_min);
}
