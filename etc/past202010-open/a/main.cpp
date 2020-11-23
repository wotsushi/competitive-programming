#include "template.hpp"

int main() {
  ll(A, B, C);
  vi X{A, B, C};
  SORT(X);
  if (A == X[1]) {
    out("A")
  } else if (B == X[1]) {
    out("B");
  } else {
    out("C");
  }
}
