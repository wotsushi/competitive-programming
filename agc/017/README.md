# AGC017

## A
カテゴリ: 数え上げ

A はすべて偶数と仮定する。このとき、解は  (1 - P) 2^N である。
A に奇数が含まれると仮定する。このとき、解は 2^{N - 1} である。

## B
カテゴリ: 全探索

隣り合うマスについて、左のマスの整数から右のマスの整数を引いた値は、非負の場合と負の場合の2通り考えられる。
非負である隣り合うマスのペアの個数を x とすれば, 負である隣り合うマスのペアの個数は N - x - 1 となる。
このとき、 一番右のマスの整数 b がとりうる範囲は A + Cx - D(N - x - 1) <= b <= A + Dx - C(N - x - 1) である。
したがって、 Cx - D(N - x - 1) <= B <= Dx - C(N - x - 1) を満たす x が存在するかを判定すればよい。
