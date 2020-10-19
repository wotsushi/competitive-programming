#include "template.hpp"

int main() {
  ll(M, K);
  if ((M == 1 and K == 1) or K > 0 and K >= (1 << M)) {
    out(-1);
    return 0;
  }
  ll N = 1 << M;
  vi ans;
  if (K == 0) {
    rep(i, N) {
      ans.push_back(i);
      ans.push_back(i);
    }
  } else {
    ans.push_back(0);
    ans.push_back(K);
    ans.push_back(0);
    rep(i, 1, N) {
      if (i != K) {
        ans.push_back(i);
      }
    }
    ans.push_back(K);
    rrep(i, 1, N) {
      if (i != K) {
        ans.push_back(i);
      }
    }
  }
  jout(ALL(ans)) << endl;
}
