#include "template.hpp"

int main() {
  ll(N, A, B);
  vll(D, B);
  SORT(D);
  D.insert(D.begin(), 0);
  D.push_back(N + 1);
  ll ans = N - B;
  repi(i, B + 1) { ans -= (D[i] - D[i - 1] - 1) / A; }
  out(ans);
}
