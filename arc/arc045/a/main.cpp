#include "template.hpp"

int main() {
  string S;
  getline(cin, S);
  vs ans;
  each(c, S) {
    if (c == 'L') {
      ans.push_back("<");
    }
    if (c == 'R') {
      ans.push_back(">");
    }
    if (c == 'A') {
      ans.push_back("A");
    }
  }
  jout(ALL(ans)) << endl;
}
