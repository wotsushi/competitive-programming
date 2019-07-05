from functools import reduce

N = int(input())
A = [int(input()) for _ in range(N)]

# 数列の末尾から構築する
ans, _ = reduce(
    lambda acc, i: (
        (
            -1 if acc[0] == -1 or A[i] < acc[1] - 1 or A[i] > i else
            acc[0] if A[i] == acc[1] - 1 else
            acc[0] + A[i]
        ),
        A[i]
    ),
    reversed(range(N)),
    (0, 0)
)

print(ans)
