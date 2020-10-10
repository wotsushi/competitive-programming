#include "template.hpp"

int main() {
  in(char, S);
  in(char, T);
  if (S == 'Y') {
    out((char)(toupper(T)));
  } else {
    out(T);
  }
}
