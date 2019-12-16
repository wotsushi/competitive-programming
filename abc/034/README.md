# ABC034

## D
カテゴリ: 二分探索

濃度をq以上に可能であるかは容易に判定できる。
なぜならば (w_1 p_1 + ... + w_K p_K) / (w_1 + ... + w_K) >= q は
((w_1 p_1 - w_1 q) + ... + (w_K p_K - w_K q) >= 0 と同値であり、
左辺はw_i p_i - w_i q について大きい値から順にK個選べばよいだけである。
あとは二分探索で最大のqを求めればよい。