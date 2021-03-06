# ABC150

## D
カテゴリ: 数学

x, yの半公倍数zはある非負の整数n, mを用いて nx + x/2 = my + y/2 = z と表される。
nx - my = y/2 - x/2 より、y/2 - x/2はgcd(x, y)で割り切れる必要がある。
このとき、lcm(x, y) / 2 はx, yの半公倍数となる。
これに基づいてaの先頭から半公倍数を畳み込めばよい。

## E
カテゴリ: 数え上げ

S, Tで値が異なる要素のうち、C_iが小さいものから順に操作を施すことになる。
Cは昇順ソートされていると仮定する。
逆にi番目の要素に対する操作コストの和を求めることを考える。
i番目の要素より小さい要素はdon't careなので、i-1番目までの要素の組合せ 2^{2(i - 1)} 通りは
そのまま掛けることができる。
i番目の要素は異なる必要があるので2通り。
i番目の要素より大きい要素について、2^{2(N - i)}通りの組合せがある。
それらの異なる要素の個数の和を求めるのは難しいが、平均は (N - i) / 2 個であることを利用する
（すべての組合せなので期待値で考えると明らか）。
すると異なる要素の個数の和は 2^{2(N - i)} * (N - i) / 2 となる。
以上より、操作コストは 2^{2(i - 1)} * 2 * 2^{2(N - i)} * (N - i) / 2 * C_i = 2^{2(N - 1)} * (N - i) * C_i となる。
これを各iについて求め、和をとればよい。
