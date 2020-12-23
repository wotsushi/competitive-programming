#include "template.hpp"

int main() {
  ll(N);
  vll(a, N);
  vll(b, N);
  ll M = max(*max_element(ALL(a)), *max_element(ALL(b)));
  vi X(M + 1);
  each(b_i, b) { ++X[b_i]; }
  vi C(M + 1);
  ll ans = N;
  each(a_i, a) {
    ++C[a_i];
    chmin(ans, X[a_i] / C[a_i]);
    out(ans);
  }
}
