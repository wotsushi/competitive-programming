#include "template.hpp"

int main() {
  ll X, Y;
  scanf("%ld/%ld", &X, &Y);
  ll m = X / Y;
  vii ans;
  for (ll N = 2 * m - 100; N <= 2 * m + 100; ++N) {
    ll s = Y * N * N + (Y - 2 * X) * N;
    ll M = s / (2 * Y);
    if (s % (2 * Y) == 0 and 1 <= M and M <= N) {
      ans.push_back({N, M});
    }
  }
  if (ans.empty()) {
    out("Impossible");
  } else {
    for (auto [N, M] : ans) {
      cout << N << ' ' << M << endl;
    }
  }
}
