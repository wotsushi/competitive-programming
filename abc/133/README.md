# ABC133

## A
カテゴリ: 数学

解は min(NA, B) である。

## C
カテゴリ: 探索

i = L, L + 1, ..., min(R - 1, L + 2019) および
j = i + 1, i + 2, ..., min(R, i + 2019) について、
ij mod 2019 の最小値を求めればよい。

## D
カテゴリ: 数学

山iに降った雨の量を 2x_i で表す。
x_i + x_{i + 1} = A_i が成り立つ。
よって、 x_1 = (A_1 - A_2 + A_3 - A_4 + ... + A_{N}) / 2 である。
x_2, ..., x_N は x_1 をもとに求めればよい。

## E
カテゴリ: 数え上げ

頂点iの次数をd_iで表す。
解は `K * (K-1)P(d_1) * (K-2)P(d_2-1) * (K-2)P(d_3-1) * ... * (K-2)P(d_N-1)` である。