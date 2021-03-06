# ABC136

## A
カテゴリ: 数学

解は max(0, C - (A - B)) である。

## B
カテゴリ: 数え上げ

解は min(9, N) + max(0, min(999, N) - 99) + max(0, min(99999, N) - 9999) である。

## C
カテゴリ: 貪欲法

先頭から順に、可能な限りマスの高さを低くする戦略により、単調非減少にできるか判定すればよい。

## D
カテゴリ: 考察

Sのi文字目をS_iで表す。10^100回の移動後に左からi番目のマスにいる子どもの人数をa_iとする。
S_j = 'L' かつ j < i を満たす最大のj（そのようなjが存在しないならばj = 0とする）を L_i で表す。
S_j = 'R' かつ j > i を満たす最小のj（そのようなjが存在しないならばj = N + 1とする） を R_i で表す。
以下が成り立つ。

* S_i = 'R' の場合:
  * S_{i + 1} = 'R' ならば a_i = 0
  * S_{i + 1} = 'L' ならば a_i = ceil((i - L_i) / 2) + floor(R_i - (i + 1) / 2)
* S_i = 'L' の場合:
  * S_{i - 1} = 'R' ならば a_i = ceil((R_i - i) / 2) + floor(((i - 1) - L_i) / 2)
  * S_{i - 1} = 'L' ならば a_i = 0

## E
カテゴリ: 数学

S = A_1 + ... + A_N とする。
解はSの約数である。
各約数dについて、K回以下の操作で、Aをすべてdの倍数にできるか判定する方法を考える。

A_1 % d, ..., A_N % d を昇順にソートした列を B_1, ..., B_N とする。
さらに、 C_i = d - B_i とする。
B_1 + ... + B_j = C_{j + 1} + ... + C_N かつ B_1 + ... + B_j <= K を満たすjが
存在するならば、かつ、そのときに限り、K回以下の操作で、Aをすべてdの倍数にできる。
