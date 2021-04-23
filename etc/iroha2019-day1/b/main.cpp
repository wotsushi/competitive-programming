#include "template.hpp"

int main() {
  STR(S);
  ll(K);
  rep(_, K) { S = S.substr(1) + S[0]; }
  out(S);
}
