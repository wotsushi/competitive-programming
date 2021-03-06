# 第二回全国統一プログラミング王決定戦予選

## A
カテゴリ: 数学

解は floor((N - 1) / 2) である。

## C
カテゴリ: 貪欲法

Aのi番目に小さい値をa_i, Bのi番目に小さい値をb_iで表す。
任意のiについて、a_i <= b_i が成り立つ必要がある。
このとき、N-1回交換すれば問題の条件を必ず満たせる。
ではN-2回以下で問題の条件を満たすのはどういった場合か？
これは、Aの要素の移動先が大きな一つのサイクルにならない場合である。
したがって、a_Nから順にどこに移動するかを計算すればよい。
移動先の候補が複数あればその時点で大きな一つのサイクルにならないことに注意する。
サイクルの判定はUnionFind木を使うと楽。

## D
カテゴリ: ダイクストラ法

頂点(i + 1)から頂点iに長さ0の辺を張っても解に影響を与えない。
これにより、L_iからR_iに長さC_iの辺を張るだけでよい。
上記のグラフに対してダイクストラ法により最短距離を求めればよい。

## E
カテゴリ: 構築

大きい方からN個の整数をcとして使うべきなのは明らか。
条件を満たす分割が可能ならば K + (K + 1) + ... + (K + 2N - 1) <= (K + 2N) + ... + (K + 3N - 1) である。
逆に上記を満たすならば、 例えば、

(6, 12, 18),
(5, 14, 19),
(4, 16, 20),
(10, 11, 21),
(9, 13, 22),
(8, 15, 23),
(7, 17, 24)

のように構築すればよい。構築のポイントは以下

* m = ceil(N / 2) とする
* a[m] = K + N - 1, a[m + 1] = K + Nのようにm番目にK + N - 1を割り当て、インデックスを1増やすたびに1ずつ減らす（インデックスはループする）
* b[1] = K + N + 1, b[2] = K + N + 3のように1番目にK + N + 1を割り当て、インデックスを1増やすたびに2ずつ増やす（m未満のインデックスまで）
* b[m] = K + N, b[m + 1] = K + N + 2のようにmにK + Nを割り当て、インデックスを1増やすたびに2ずつ増やす
* cは小さい順に並べるだけ
