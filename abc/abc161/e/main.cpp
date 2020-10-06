#include "template.hpp"

int main() {
  ll(N, K, C);
  STR(S);
  vb R(N);
  ll x = 0;
  rrep(i, N) {
    if (S[i] == 'o') {
      R[i] = true;
      ++x;
      i -= C;
      if (x >= K) {
        rrep(j, i) {
          if (S[j] == 'o') {
            return 0;
          }
        }
      }
    }
  }
  vi ans;
  rep(i, N) {
    if (S[i] == 'o') {
      if (R[i]) {
        ans.push_back(i + 1);
      }
      i += C;
    }
  }
  each(d, ans) { out(d); }
}
