# ABC129

## A
カテゴリ: 実装

やるだけ。

## B
カテゴリ: 全探索

やるだけ。

## C
カテゴリ: 動的計画法

i段目にたどりつくまでの移動方法を f(i) とする。
f(i) について以下が成り立つ。

* f(0) = 1
* i が a に含まれるならば f(i) = 0
* 1 が a に含まれないならば f(1) = 1
* 上記以外の場合、 f(i) = f(i - 1) + f(i - 2)

解は f(N) である。

## D
カテゴリ: 実装

各マスについて、横方向に照らすマスの数xと縦方向に照らすマスの数をy求める。
解は x + y - 1 の最大値である。

## E
カテゴリ: 数学

解を `f(L)` で表す。
nを非負整数として、 `L = 2^n - 1` ならば `f(L) = 3^n` である。
一般に、nを非負整数、mを 1 <= m <= 2^(n - 1) として、 `L = 2^n - m` と表せる。
このとき、 `f(L) = f(2^(n - 1) - 1) + 2f(L - 2^(n - 1)) = 3^(n - 1) + 2f(2^(n - 1) - m` が成り立つ。

`L` は二進数表記で与えられ、非常に大きい値なので、上記の漸化式では計算できない。
そこで、計算を簡単にするため、fをもとに漸化式gを以下で定義する。

* n = 0 ならば `g(n) = 1`
* Lの下位から数えてnビット目が1ならば、 `g(n) = 3^(n - 1) + 2g(n - 1)`
* そうでなければ、`g(n) = g(n - 1)`

解は `g(n)` である。