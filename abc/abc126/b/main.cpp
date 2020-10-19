#include "template.hpp"

int main() {
  STR(S);
  ll a = stoll(S.substr(0, 2));
  ll b = stoll(S.substr(2, 2));
  auto f = [&](ll x) { return 1 <= x and x <= 12; };
  string ans;
  if (f(a) and f(b)) {
    ans = "AMBIGUOUS";
  }
  if (f(a) and not f(b)) {
    ans = "MMYY";
  }
  if (not f(a) and f(b)) {
    ans = "YYMM";
  }
  if (not f(a) and not f(b)) {
    ans = "NA";
  }
  out(ans);
}
