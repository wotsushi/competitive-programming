#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  // 入力
  ll N, K;
  cin >> N >> K;
  vector<ll> x(N + 1), y(N + 1);
  vector<char> c(N + 1);
  for (int i = 1; i <= N; ++i) { cin >> x[i] >> y[i] >> c[i]; }

  // 各クエリを(0, 0)から(K -1, K - 1) の矩形にマッピングし、各マスの個数をカウント
  ll K2 = 2 * K;
  vector<vector<ll>> cs(K2, vector<ll>(K2, 0));
  for (int i = 1; i <= N; i++) {
    if (c[i] == 'B') { cs[x[i] % K2][y[i] % K2]++; }
    else { cs[(x[i] + K) % K2][y[i] % K2]++; }
  }
  // dp[i][j] はマス(i, j) から K*K のマスを黒で塗るときに叶えられる要望の数
  vector<vector<ll>> dp(K2, vector<ll>(K2, 0));
  // 累積和を用いて解を求める
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      dp[0][0] += cs[i][j];
    }
  }
  for (int i = 1; i < K2; i++) {
    dp[i][0] = dp[i - 1][0];
    dp[0][i] = dp[0][i - 1];
    for (int j = 0; j < K; j++) {
        dp[i][0] += cs[(i + K - 1) % K2][j] - cs[i - 1][j];
        dp[0][i] += cs[j][(i + K - 1) % K2] - cs[j][i - 1];
    }
  }
  for (int i = 1; i < K2; i++) {
      for (int j = 1; j < K2; j++) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] +
                     cs[(i + K - 1) % K2][(j + K - 1) % K2] +
                     cs[i - 1][j - 1] - cs[i - 1][(j + K - 1) % K2] -
                     cs[(i + K - 1) % K2][j - 1];
      }
  }
  # 全通りの塗り方を試し、解を求める
  ll ans = 0;
  for (int i = 0; i < K2; i++) {
      for (int j = 0; j < K2; j++) {
          ans = max(ans, dp[i][j] + dp[(i + K) % K2][(j + K) % K2]);
      }
  }
  // 出力
  cout << ans << endl;
  return 0;
}
