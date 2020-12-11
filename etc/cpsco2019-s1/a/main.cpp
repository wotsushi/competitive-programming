#include "template.hpp"

int main() {
  ll(N, A);
  ll ans_min = (A + 2) / 3;
  ll ans_max = min(N / 3, A);
  cout << ans_min << ' ' << ans_max << endl;
}
