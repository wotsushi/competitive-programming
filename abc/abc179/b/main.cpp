#include "template.hpp"

int main() {
  ll(N);
  auto D = vec(ll, N, 2);
  rep(i, N) { cin >> D[i][0] >> D[i][1]; }
  rep(i, N - 2) {
    bool ok = true;
    rep(j, 3) { ok &= D[i + j][0] == D[i + j][1]; }
    if (ok) {
      out("Yes");
      return 0;
    }
  }
  out("No");
}
