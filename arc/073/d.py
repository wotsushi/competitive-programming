from itertools import accumulate, product

# 入力
N, W = map(int, input().split())
w, v = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

# 各重さの物のリスト（価値について降順）
u = [
    [0] + list(
        accumulate(
            sorted(
                (
                    y for x, y in zip(w, v)
                    if x == i
                ),
                reverse=True
            )
        )
    )
    for i in range(w[0], w[0] + 4)
]

# 重さが w_1, w_1 + 1, w_1 + 2 の物をa, b, c 個選んだとき、
# 重さが w_1 + 3 の物の選び方は一意に定まることを用いて最適値を求める
ans = max(
    sum(u[i][k] for i, k in enumerate(t)) +
    u[3][
        min(
            len(u[3]) - 1,
            (W - sum(k * (w[0] + i) for i, k in enumerate(t))) // (w[0] + 3)
        )
    ]
    for t in product(*map(range, map(len, u[:3])))
    if sum(k * (w[0] + i) for i, k in enumerate(t)) <= W
)

# 出力
print(ans)
