# AGC006

## A
カテゴリ: 全探索

Sの末尾m文字とTの先頭m文字が等しくなるような最大のmを求める。
解は2N - mである。

## B
カテゴリ: 構築

x = 1, 2N - 1ならば No.
x = 2 ならば (N, N - 1, ..., 2, 1, N + 1, ..., 2N - 1).
3 <= x <= 2N - 1 ならばp = (p_1, ..., p_{2N - 1}) として、以下を満たす順列pを解とすればよい。

* p_{N - 2} = x - 2
* p_{N - 1} = x + 1
* p_{N} = x
* p_{N + 1} = x - 1

