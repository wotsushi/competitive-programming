#include "template.hpp"

int main() {
  ll(N);
  if (N & 1) {
    return 0;
  }

  auto f = def([&](auto&& f, ll i, ll k, string s) {
    if (i == N) {
      out(s);
      return;
    }
    if (N - i > k) {
      f(i + 1, k + 1, s + '(');
    }
    if (k > 0) {
      f(i + 1, k - 1, s + ')');
    }
  });
  f(0, 0, "");
}
