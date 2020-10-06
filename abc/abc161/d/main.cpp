#include "template.hpp"

int main() {
  ll(K);
  queue<ll> q;
  repi(i, 9) { q.push(i); }
  ll ans;
  rep(_, K) {
    ans = q.front();
    q.pop();
    ll k = ans % 10;
    if (k >= 1) {
      q.push(10 * ans + k - 1);
    }
    q.push(10 * ans + k);
    if (k <= 8) {
      q.push(10 * ans + k + 1);
    }
  }
  out(ans);
}
