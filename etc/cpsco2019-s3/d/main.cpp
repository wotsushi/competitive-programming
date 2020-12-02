#include "template.hpp"

int main() {
  ll(N);
  STR(S);
  bool ok = false;
  rep(i, N - 2) {
    if (S.substr(i, 3) == "RGB") {
      S[i] = '.';
      S[i + 1] = '.';
      S[i + 2] = '.';
      ok = true;
    }
  }
  rep(i, N) {
    ok &= not(S[i] == 'R' and (i > N - 3 or S[i + 1] == 'B'));
    ok &= not(S[i] == 'G' and (i == 0 or i == N - 1 or S[i + 1] == 'G'));
    ok &= not(S[i] == 'B' and (i <= 1));
  }
  yes(ok);
}
