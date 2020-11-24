#include "template.hpp"

int main() {
  vvll(c, 3);
  bool ok = true;
  rep(i, 2) {
    ok &= c[i + 1][0] - c[i][0] == c[i + 1][1] - c[i][1] and
          c[i + 1][1] - c[i][1] == c[i + 1][2] - c[i][2];
  }
  yes(ok);
}
