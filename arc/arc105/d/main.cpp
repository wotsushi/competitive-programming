#include "template.hpp"

int main() {
  ll(T);
  rep(_, T) {
    ll(N);
    vll(a, N);
    string ans = "Second";
    if ((N & 1) == 0) {
      SORT(a);
      rep(i, N / 2) {
        if (a[2 * i] != a[2 * i + 1]) {
          ans = "First";
        }
      }
    }
    out(ans);
  }
}
