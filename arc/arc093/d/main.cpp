#include "template.hpp"

const int h = 100;
const int w = 100;

int main() {
  ll(A, B);
  vs s(h, string(w, '.'));
  rep(i, h / 2, h) { s[i] = string(w, '#'); }
  auto f = [&](ll r, char c, ll m) {
    for (ll i = 1; i < h / 2; i += 2) {
      for (ll j = 1; j < w; j += 2) {
        if (m > 0) {
          s[i + r][j] = c;
          --m;
        }
      }
    }
  };
  f(0, '#', B - 1);
  f(h / 2, '.', A - 1);
  cout << h << ' ' << w << endl;
  each(si, s) { out(si); }
}
