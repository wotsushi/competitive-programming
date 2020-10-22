#include "template.hpp"

int main() {
  ll(A, B);
  auto f = [&](ll x) {
    ll res = 0;
    rep(_, 4) {
      res ^= x;
      if (x % 4 == 0) {
        break;
      }
      --x;
    }
    return res;
  };
  ll ans = f(B) ^ f(max(0LL, A - 1));
  out(ans);
}
