#include "template.hpp"

int main() {
  ll(N);
  STR(s);
  ll ans = N;
  vi X;
  each(c, s) {
    if (c == 'f') {
      X.push_back(0);
    } else if (c == 'o' and not X.empty() and X.back() == 0) {
      X.pop_back();
      X.push_back(1);
    } else if (c == 'x' and not X.empty() and X.back() == 1) {
      X.pop_back();
      ans -= 3;
    } else {
      X.clear();
    }
  }
  out(ans);
}
