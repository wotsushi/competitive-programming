#include "template.hpp"
using mint = static_modint<10007>;

int main() {
  ll(n);
  vec<mint> a{0, 0, 0, 1};
  repi(i, 4, n) { a.push_back(a[i - 1] + a[i - 2] + a[i - 3]); }
  out(a[n]);
}
