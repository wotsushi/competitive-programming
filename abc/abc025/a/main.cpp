#include "template.hpp"

int main() {
  STR(S);
  ll(N);
  --N;
  string ans(2, ' ');
  ans[0] = S[N / 5];
  ans[1] = S[N % 5];
  out(ans);
}
