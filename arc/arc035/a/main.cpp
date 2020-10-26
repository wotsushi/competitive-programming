#include "template.hpp"

int main() {
  STR(s);
  ll N = s.size();
  rep(i, N) {
    if (s[i] != s[N - i - 1] and s[i] != '*' and s[N - i - 1] != '*') {
      out("NO");
      return 0;
    }
  }
  out("YES");
}
