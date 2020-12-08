#include "template.hpp"

int main() {
  STR(W);
  string ans;
  each(c, W) {
    if (c != 'a' and c != 'i' and c != 'u' and c != 'e' and c != 'o') {
      ans.push_back(c);
    }
  }
  out(ans);
}
