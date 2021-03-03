#include "template.hpp"

int main() {
  ll(N);
  ll ans = 0;
  for (ll i = 1; i * (i + 1) <= 2 * N; ++i) {
    ll ok = N;
    ll ng = 0;
    while (ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      if ((2 * mid + i - 1) * i / 2 >= N) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    ans += ((2 * ok + i - 1) * i / 2) == N;
  }
  ans *= 2;
  out(ans);
}
