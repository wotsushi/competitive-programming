# AGC003

## A
カテゴリ: 考察

Sに含まれる文字xの個数をC[x] で表す。
(C[N] >= 1 xor C[S] >= 0) or (C[N] >= 1 xor C[S] >= 0) ならば 'No' である。

## B
カテゴリ: 貪欲法

可能な限り小さい整数のペアから順に貪欲に作ればよい。

## C
カテゴリ: 考察

i番目の要素がj番目に小さい要素とする。
iとjがともに奇数またはともに偶数ならば操作2のみで適切な位置に移動できる。
そうでない場合、操作1を使わなければ適切な位置に移動できない。
したがって、iとjのうち、一方が奇数であり一方が偶数である要素の数を2で割った値が解となる
（そのような要素数は必ず偶数である）。
