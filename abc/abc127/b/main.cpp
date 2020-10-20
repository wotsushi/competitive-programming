#include "template.hpp"

int main() {
  ll(r, D, x_2000);
  ll x = x_2000;
  rep(_, 10) {
    x = r * x - D;
    out(x);
  }
}
