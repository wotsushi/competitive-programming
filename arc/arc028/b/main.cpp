#include "template.hpp"

int main() {
  ll(N, K);
  vll(X, N);
  priority_queue<ii> q;
  rep(i, K) { q.push({X[i], i + 1}); }
  out(q.top().second);
  rep(i, K, N) {
    if (X[i] < q.top().first) {
      q.pop();
      q.push({X[i], i + 1});
    }
    out(q.top().second);
  }
}
