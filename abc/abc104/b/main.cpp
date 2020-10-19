#include "template.hpp"

int main() {
  STR(S);
  ll u = S.find('A');
  ll v = S.find('C');
  rep(i, S.size()) {
    if (i != u and i != v and isupper(S[i])) {
      out("WA");
      return 0;
    }
  }
  yes(u == 0 and 2 <= v and v <= S.size() - 2, "AC", "WA");
}
