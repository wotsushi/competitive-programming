from itertools import accumulate
from bisect import bisect

N, Q = map(int, input().split())
A = list(map(int, input().split()))
X = [int(input()) for _ in range(Q)]

# xに応じて、高橋くんが先頭から何枚連続とれるかを
# 前処理により求めておく
INF = 10**20
B = A[::-1]
Y = [(B[i] + B[2 * i]) // 2 + 1 for i in range(1, (N + 1) // 2)][::-1]
acc1 = list(accumulate(B))
acc2 = list(accumulate(B[2::2][::-1]))[::-1] + [0] * (N - (N - 1) // 2)
ans = '\n'.join(
    str(acc1[i] + acc2[i])
    for i in (
        len(Y) - bisect(Y, x)
        for x in X
    )
)

print(ans)
