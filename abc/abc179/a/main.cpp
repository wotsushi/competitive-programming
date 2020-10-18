#include "template.hpp"

int main() {
  STR(S);
  string ans;
  if (S.back() == 's') {
    ans = S + "es";
  } else {
    ans = S + "s";
  }
  out(ans);
}
