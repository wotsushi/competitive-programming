# ABC085

## C
カテゴリ: 全探索

0 <= x <= N, 0 <= y <= N - x を満たす整数x, yについて
10000x + 5000x + 1000(N - x - y) = Y を満たすx, yが存在するか全探索すればよい。

## D
カテゴリ: 貪欲法

振るべき刀は高々一本である。
振るべき刀を振ったときより、投げたときのダメージの小さい刀は使わない。
以上の考察をもとに、以下の戦略で攻撃すればよい。

* 投げるべき刀について、ダメージの大きい順から順に刀を投げる
  * 途中で魔物が消滅したらその時点で終了
  * 振るべき刀も投げてよい（この後、その刀を振る可能性があるが、投げた後に振っても解は変わらない）。
* 魔物が消滅するまで振るべき刀を振る


