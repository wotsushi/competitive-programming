#include "template.hpp"

int main() {
  STR(S);
  ll(T);
  ll x = 0;
  ll y = 0;
  ll z = 0;
  each(c, S) {
    if (c == 'L') {
      --x;
    } else if (c == 'R') {
      ++x;
    } else if (c == 'U') {
      ++y;
    } else if (c == 'D') {
      --y;
    } else {
      ++z;
    }
  }
  ll ans;
  ll p = abs(x) + abs(y);
  if (T == 1) {
    ans = p + z;
  } else {
    if (p >= z) {
      ans = p - z;
    } else {
      ans = (z - p) & 1;
    }
  }
  out(ans);
}
