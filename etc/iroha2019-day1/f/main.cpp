#include "template.hpp"

int main() {
  ll(N, K);
  vi ans;
  for (ll i = 2; i * i <= N; ++i) {
    while (N % i == 0 and K >= 2) {
      ans.push_back(i);
      N /= i;
      --K;
    }
  }
  if (K >= 2) {
    out(-1);
  } else {
    ans.push_back(N);
    jout(ALL(ans)) << endl;
  }
}
