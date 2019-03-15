from functools import reduce
from math import ceil

# 入力
N, H = map(int, input().split())
a, b = zip(*(map(int, input().split()) for _ in range(N)))

# 投げるべき刀を強力なものから投げる。その後、振るべき刀を降り続ける。
m = max(a)
c = sorted(filter(lambda x: x > m, b), reverse=True)
ans = (
    reduce(
        lambda acc, e: (acc[0] + 1, acc[1] + e) if acc[1] < H else acc,
        c,
        (0, 0)
    )[0] if sum(c) >= H else
    len(c) + ceil((H - sum(c)) / m)
)

# 出力
print(ans)
