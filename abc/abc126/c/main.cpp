#include "template.hpp"

int main() {
  ll(N, K);
  double ans = 0;
  repi(i, N) {
    double p = 1;
    for (ll j = i; j < K; j *= 2) {
      p /= 2;
    }
    ans += p / N;
  }
  fout(ans);
}
