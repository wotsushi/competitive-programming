#include "template.hpp"
using mint6 = static_modint<6>;
using mint11 = static_modint<11>;

int main() {
  STR(N);
  mint6 k6 = 1;
  mint11 k11 = 1;
  mint6 m6 = 0;
  mint11 m11 = 0;
  rrep(i, N.size()) {
    m6 += k6 * (N[i] - '0');
    m11 += k11 * (N[i] - '0');
    k6 *= 10;
    k11 *= 10;
  }
  yes(m6 == 0, "yES", "nO");
  yes(m11 == 0, "yES", "nO");
}
