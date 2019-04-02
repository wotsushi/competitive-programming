# ABC084

## D
カテゴリ: 累積和

i = 1, 2, ..., 10**5 について、 dp[i] を1以上i以下の2017に似た数となる奇数の個数とする。
便宜のため、 dp[0] = 0 とする。
各クエリ (l_i, r_i) に対する解は dp[r_i] - dp[l_i - 1] である。