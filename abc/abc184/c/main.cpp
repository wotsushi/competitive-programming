#include "template.hpp"

int main() {
  ll(r_1, c_1);
  ll(r_2, c_2);
  auto f = [&](ll a, ll b, ll c, ll d) {
    return a + b == c + d or a - b == c - d or abs(a - c) + abs(b - d) <= 3;
  };
  ll ans;
  if (r_1 == r_2 and c_1 == c_2) {
    ans = 0;
  } else if (f(r_1, c_1, r_2, c_2)) {
    ans = 1;
  } else {
    bool ok = (r_1 + c_1) % 2 == (r_2 + c_2) % 2;
    repi(i, r_1 - 3, r_1 + 3) {
      repi(j, c_1 - 3, c_1 + 3) {
        ok |= f(r_1, c_1, i, j) and f(i, j, r_2, c_2);
      }
    }
    if (ok) {
      ans = 2;
    } else {
      ans = 3;
    }
  }
  out(ans);
}
