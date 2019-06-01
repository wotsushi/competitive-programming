from functools import reduce
from itertools import chain

# 入力
N, M = map(int, input().split())
A = list(map(int, input().split()))
B, C = (
    zip(*(map(int, input().split()) for _ in range(M))) if M else
    ((), ())
)

# 最終形について、大きい整数から順に整数を割り当てる
ans, _ = reduce(
    lambda acc, t: (
        acc[0] + t[0] * min(N - acc[1], t[1]),
        min(N, acc[1] + t[1])
    ),
    sorted(
        chain(
            ((a, 1) for a in A),
            zip(C, B)
        ),
        reverse=True
    ),
    (0, 0)
)

# 出力
print(ans)
