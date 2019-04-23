# ARC004

## A
カテゴリ: 全探索

やるだけ。

## B
カテゴリ: 幾何

d を降順 d' (d'_0 > d'_1 > ... > d'_{N - 1}) に並び替えると分かりやすい。
d'_0 <= d'_1 + d'_2 + ... + d'_{N - 1} ならば点0と点Nは同一点にできる。
d'_0 > d'_1 + d'_2 + ... + d'_{N - 1} ならば点Nは点0から
d'_0 - (d'_1 + d'_2 + ... + d'_{N - 1}) だけ離れた位置にプロットするのが
最適である。
解は、 max(0, 2 * max(d) - (d_0 + d_1 + ... + d_{N - 1})) である。

## C
カテゴリ: 数学

1 <= M <= N より、以下が成り立つ。

* ((1 + ... + N) - M) / N >= ((2 + ... + N) / N = (N - 1) / 2
* ((1 + ... + N) - M) / N < ((1 + ... + N) / N = (N + 1) / 2

((1 + ... + N) - M) / N = X / Y より、 (N - 1) / 2 <= X / Y < (N + 1) / 2 を得る。
したがって、 2X / Y - 1 < N <= 2X / Y + 1 が成り立つ。
これより、 N の候補は以下の通り。

* 2X / Y が整数ならば N = 2X / Y, 2X / Y + 1 である。
* 2X / Y が整数でなければ N = ceil(2X / Y) - 1, ceil(2X / Y) である。

M = ((1 + ... + N) - NX / Y) = N(N + 1) / 2 - NX / Y より、
各 N の候補について、 M の値を求め、 1 <= M <= N ならばそのような (N, M) は解である。