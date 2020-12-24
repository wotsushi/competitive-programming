#include "template.hpp"

int main() {
  in(char, C_1);
  ll(A);
  in(char, C_2);
  ll(B);
  ll ans =
      abs((C_1 == 'E' ? 1 : -1) * (A / 15) - (C_2 == 'E' ? 1 : -1) * (B / 15));
  out(ans);
}
