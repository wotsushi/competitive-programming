#include "template.hpp"

int main() {
  ll(l_1, l_2, l_3);
  ll x = max({l_1, l_2, l_3});
  ll y = min({l_1, l_2, l_3});
  ll ans = 2 * (x + y) - (l_1 + l_2 + l_3);
  out(ans);
}
