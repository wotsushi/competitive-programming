# ABC130

## A
カテゴリ: 実装

やるだけ。

## B
カテゴリ: 実装

やるだけ。

## C
カテゴリ: 幾何

面積は必ず二等分できる。
また、面積を二等分する直線は必ず長方形の対角線の交点を通る。
したがって、(x, y) = (W / 2, y / 2) を満たすか判定すればよい。

## D
カテゴリ: 累積和

f(i) を a_i + ... + a_j >= K を満たす最小のjとする。
g(i) = N - f(i) + 1 とする。
解は g(1) + ... + g(N) である。

## E
カテゴリ: 動的計画法

Sの先頭からi文字目までの部分文字列S[i]とTの先頭からj文字目までの部分文字列T[j]についての
解をdp[i][j]とする。
dp[i][j]について、以下が成り立つ。

* i = 0 または j = 0 ならば dp[i][j] = 1
* S_i = T_j ならば dp[i][j] = 2dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - 2dp[i - 1][j - 1] = dp[i - 1][j] + dp[i][j - 1]
* そうでなければ dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]

解は dp[N][M] である。