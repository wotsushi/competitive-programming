# ARC089

## C
カテゴリ: 考察

d_i = |x_{i + 1} - x_i| + |y_{i + 1} - y_i|, dt_i = t_{i + 1} - t_i とする。
各iについて、d_i <= dt_i かつ (dt_i - d_i) % 2 = 0 ならば 'Yes',
そうでなければ 'No' である。

## D
カテゴリ: 累積和

各要望に対して (x_i, y_i) をそれぞれ 2K で割った余りに変換して考えても等価であることを利用する。
黒で塗りたい変換後の要望が (0, 0), (0, 1), ..., (0, 2K - 1), (1, 0), (1, 1), ..., (1, 2K - 1),
..., (2K - 1, 0), (2K - 1, 1), ..., (2K - 1, 2K - 1) である個数をそれぞれ求める。
白に塗りたい要望についても同様に求める。
全探索により、叶える要望の個数を最大化する K*K の塗り替え方を求めればよい。
このとき、累積和を用いることで O(K^2) で全探索可能。



