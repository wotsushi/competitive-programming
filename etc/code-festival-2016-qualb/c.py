from functools import reduce

# 入力
W, H = map(int, input().split())
p = [int(input()) for _ in range(W)]
q = [int(input()) for _ in range(H)]

# クラスカル法に基づいて解を求める
ans, _, _ = reduce(
    lambda acc, c: (
        (
            acc[0] + (H - acc[2] + 1) * c[0] if c[1] == 0 else
            acc[0] + (W - acc[1] + 1) * c[0]
        ),
        (
            acc[1] + 1 if c[1] == 0 else
            acc[1]
        ),
        (
            acc[2] + 1 if c[1] == 1 else
            acc[2]
        )
    ),
    sorted([(P, 0) for P in p] + [(Q, 1) for Q in q]),
    (0, 0, 0)
)

# 出力
print(ans)
