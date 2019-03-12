from itertools import product
# 入力
N, A, B, C = map(int, input().split())
l = [int(input()) for _ in range(N)]

# 各竹について長さA, B, C, 使用しないのいずれとして使うかを全探索
ans = min(
    sum(
        abs(sum(x for k, x in zip(p, l) if k == r) - y) + 10 * (p.count(r) - 1)
        for r, y in enumerate((A, B, C), 1)
    )
    for p in product(range(4), repeat=N)
    if {1, 2, 3} <= set(p)
)

# 出力
print(ans)
