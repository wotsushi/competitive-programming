#include "template.hpp"

int main() {
  STR(S);
  each(c, S) {
    if (c == 'O') {
      c = 'A';
    } else if (c == 'A') {
      c = 'O';
    }
  }
  out(S);
}
