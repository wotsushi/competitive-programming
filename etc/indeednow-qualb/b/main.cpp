#include "template.hpp"

int main() {
  STR(s);
  STR(t);
  ll N = s.size();
  rep(i, N + 1) {
    if (s == t) {
      out(i);
      return 0;
    }
    char c = s.back();
    s.insert(s.begin(), c);
    s.pop_back();
  }
  out(-1);
}
