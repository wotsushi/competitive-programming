# SoundHound Inc. Programming Contest 2018 -Masters Tournament-

## A
カテゴリ: 実装

やるだけ

## B
カテゴリ: 実装

やるだけ

## E
カテゴリ: 探索

与えられたグラフから（適当な）全域木 T を選ぶ。
頂点1を白で塗る。
Tにおいて、頂点1との距離が偶数である頂点を黒で、奇数である頂点を白で塗る。
頂点1に1を書き込む。
どの辺iについても、iの端点の和が s_i となるように頂点に整数を書き込む（正の整数でなくともよい）。
頂点kに書き込まれた整数を a[k] とする。
白の頂点に書かれている整数のうち、最小の整数をW,
黒の頂点に書かれている整数のうち、最小の整数をB とする。
Tについて、問題の条件を満たすためには、 頂点1に [2 - W, B] に含まれる整数を書き込む必要がある
（2 - W > B ならばこの時点で解は0だと分かる）。
また、Tが元のグラフに等しいならば W + B - 1 が解である（以降は考えなくてよい）。

Tに含まれない辺が存在するならば、解は0か1である。
Tに含まれない各辺j = (u_j, v_j),
その端点であるu_jとv_jの色の組合せについて、解が1であるための必要十分条件は以下である。

以下を満たす整数 1 - W <= d < B が存在する。
* (白, 白)ならば d = (s_j - (a[u_j] +　a[v_j])) / 2 について、 dが整数、かつ、 1 - W <= d < B を満たす
* (黒, 黒)ならば d = ((a[u_j] +　a[v_j]) - s_j) / 2 について、 dが整数、かつ、 1 - W <= d < B を満たす
* (白, 黒)または(黒, 白)ならば a[u_j] + a[v_j] = s_j を満たす

上記を満たさない場合、解は0である。
