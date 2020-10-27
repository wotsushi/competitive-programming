#include "template.hpp"

int main() {
  STR(s);
  ll N = s.size();
  ll p = 0;
  each(c, s) { p += c == 'p'; }
  ll ans = N / 2 - p;
  out(ans);
}
