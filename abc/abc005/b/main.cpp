#include "template.hpp"

int main() {
  ll(N);
  vll(T, N);
  ll ans = *min_element(ALL(T));
  out(ans);
}
