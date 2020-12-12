#include "template.hpp"

int main() {
  STR(S);
  vi C(26);
  ll x;
  each(c, S) {
    ++C[c - 'a'];
    x = C[c - 'a'];
  }
  bool ok = true;
  rep(i, 26) { ok &= C[i] == 0 or C[i] == x; }
  yes(ok);
}
