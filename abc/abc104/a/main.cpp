#include "template.hpp"

int main() {
  ll(R);
  string ans;
  if (R < 1200) {
    ans = "ABC";
  } else if (R < 2800) {
    ans = "ARC";
  } else {
    ans = "AGC";
  }
  out(ans);
}
