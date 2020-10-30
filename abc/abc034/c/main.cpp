#include "comb.hpp"
#include "template.hpp"
using mint = modint1000000007;

int main() {
  ll(W, H);
  comb<mint> comb(W + H);
  mint ans = comb.c(W + H - 2, W - 1);
  out(ans);
}
