from functools import reduce
from operator import xor


N = int(input())
a = list(map(int, input().split()))


# 右の箱から順に詰める
dp = [0 for _ in range(N + 1)]
for i in range(N, 0, -1):
    dp[i] = reduce(
        xor,
        (dp[j] for j in range(2 * i, N + 1, i)),
        a[i - 1]
    )
b = [i for i in range(1, N + 1) if dp[i]]
ans = (
    '0' if len(b) == 0 else
    '{}\n{}'.format(
        len(b),
        ' '.join(map(str, b))
    )
)

print(ans)
