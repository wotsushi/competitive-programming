#include "template.hpp"

int main() {
  ll(N, M);
  ll ans;
  if (N == 1 and M == 1) {
    ans = 1;
  } else if (N == 1 and M >= 2) {
    ans = M - 2;
  } else if (N >= 2 and M == 1) {
    ans = N - 2;
  } else {
    ans = (N - 2) * (M - 2);
  }
  out(ans);
}
