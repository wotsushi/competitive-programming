from collections import Counter
from itertools import permutations

N = int(input())
x, y = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

# (p, q) = (x_i - x_j, y_i - y_j) を満たす組(i, j)の個数が最大となるように
# p, qを定めればよい
ans = (
    1 if N == 1 else
    N - max(
        Counter(
            (x[i] - x[j], y[i] - y[j])
            for i, j in permutations(range(N), 2)
        ).values()
    )
)

print(ans)
