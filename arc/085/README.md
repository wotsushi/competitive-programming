# ARC085

## C
カテゴリ: 数学

解は (200N + 3600M) * 2**M である。

## D
カテゴリ: 動的計画法

漸化式dp_X[i], dp_Y[i]を以下で定義する。

* i = N ならば dp_X[i] = max(abs(W - a_1), dp_Y[1], ..., dp_Y[i - 1])
* i <= N -1 ならば dp_X[i] = max(abs(a_{i + 1} - a_1), dp_Y[1], ..., dp_Y[i - 1])
* i = N ならば dp_Y[i] = min(abs(Z - a_1), dp_X[1], ..., dp_X[i - 1])
* i <= N -1 ならば dp_Y[i] = min(abs(a_{i + 1} - a_1), dp_X[1], ..., dp_X[i - 1])

解は dp_X[N] である。
