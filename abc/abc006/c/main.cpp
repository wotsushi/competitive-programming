#include "template.hpp"

int main() {
  ll(N, M);
  M -= 2 * N;
  rep(z, N + 1) {
    ll y = M - 2 * z;
    ll x = N - (y + z);
    if (0 <= x and x <= N and 0 <= y and y <= N) {
      cout << x << ' ' << y << ' ' << z << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;
}
