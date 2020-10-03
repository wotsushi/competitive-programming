#include "template.hpp"

int main() {
  ll(N);
  STR(S);
  ll ans = 0;
  rep(i, N) {
    map<char, ll> c;
    rep(j, i, N) {
      ++c[S[j]];
      ans += c['A'] == c['T'] and c['C'] == c['G'];
    }
  }
  out(ans);
}
