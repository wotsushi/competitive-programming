# ABC017

## C
カテゴリ: いもす法

始点について昇順ソートした優先度付きキューAと終点について昇順ソートした優先度付きキューBを用意する。
宝石1から順に、その宝石を取得しないとした場合に得られるスコアを求める方針を採用する。
Bに入っている遺跡がスコアの対象にならない遺跡である。
最初はすべての遺跡をAに挿入する。
始点が1である遺跡をAからBに移す。このとき、移された遺跡はスコアの対象から外す。
次に終点が1未満である遺跡をBから除外する（そのような遺跡は存在しないが...）。
同様に、2以上のiについて、始点がiである遺跡をAからBに移す。このとき、移された遺跡はスコアの対象から外す。
次に終点がi未満である遺跡をBから除外する。
これを繰り返しスコアの最大値を求めればよい。

## D
カテゴリ: 動的計画法

dp[残りのサプリメントの個数]を求めればよい。
計算を高速化するため、dpの累積和を求めておくと効率化できる。
