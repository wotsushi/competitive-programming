#include "template.hpp"

int main() {
  ll(X, Y);
  if (Y == 0) {
    out("ERROR");
    return 0;
  }
  double ans = ((100 * X) / Y) / 100.0;
  cout << fixed << setprecision(2) << ans << endl;
}
