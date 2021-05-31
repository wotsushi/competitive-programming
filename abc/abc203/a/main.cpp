#include "template.hpp"

int main() {
  ll(a, b, c);
  ll ans;
  if (a == b or b == c or c == a) {
    ans = a ^ b ^ c;
  } else {
    ans = 0;
  }
  out(ans);
}
