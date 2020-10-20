#include "template.hpp"

int main() {
  ll(A, B);
  ll ans;
  if (A >= 13) {
    ans = B;
  } else if (A >= 6) {
    ans = B / 2;
  } else {
    ans = 0;
  }
  out(ans);
}
