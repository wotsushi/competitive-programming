#include "template.hpp"

int main() {
  ll(N);
  if (N == 2) {
    out(1);
    return 0;
  }
  ll ans = 2;
  for (ll K = 2; K * K <= N; ++K) {
    if (N % K == 0) {
      ll n = N;
      while (n % K == 0) {
        n /= K;
      }
      ans += n % K == 1;
      n = N;
      ll k = N / K;
      if (k > K) {
        while (n % k == 0) {
          n /= k;
        }
        ans += n % k == 1;
      }
    }
    if (N % K == 1) {
      ++ans;
      ans += (N - 1) / K > K;
    }
  }
  out(ans);
}
