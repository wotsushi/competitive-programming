#include "grid.hpp"
#include "template.hpp"

int main() {
  ll(H, W);
  ll(Q);
  auto f = [&](ll r, ll c) { return r * W + c; };
  auto R = vec(bool, H, W);
  dsu dsu(H * W);
  rep(i, Q) {
    ll(t);
    if (t == 1) {
      ll(r, c);
      --r;
      --c;
      R[r][c] = true;
      way4(r, c, H, W, [&](ll u, ll v) {
        if (R[u][v]) {
          dsu.merge(f(r, c), f(u, v));
        }
      });
    } else {
      ll(ra, ca, rb, cb);
      --ra;
      --ca;
      --rb;
      --cb;
      yes(R[ra][ca] and R[rb][cb] and dsu.same(f(ra, ca), f(rb, cb)));
    }
  }
}
