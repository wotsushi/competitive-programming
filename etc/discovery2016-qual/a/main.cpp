#include "template.hpp"

const string s = "DiscoPresentsDiscoveryChannelProgrammingContest2016";

int main() {
  ll(W);
  string ans;
  each(c, s) {
    ans.push_back(c);
    if (ans.size() == W) {
      out(ans);
      ans = "";
    }
  }
  if (ans.size() > 0) {
    out(ans);
  }
}
