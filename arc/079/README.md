# ARC079

## D
カテゴリ: 構築

N = 50 で決め打ちする。M = K % N とする。
a_i を以下の通り定めればよい。

* 1 <= i <= M について、 a_i = ceil(K / N)(N + 1) + N - (K + 1)
* M < i <= N について、 a_i = floor(K / N)(N + 1) + N - (K + 1)

## E
カテゴリ: 実装

最大の要素について、まとめて操作を実行しても操作回数は変わらない。
このことを利用してシミュレーションすればよい。