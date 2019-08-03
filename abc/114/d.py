from math import factorial
from itertools import permutations

N = int(input())

M = factorial(N)


primes = [True for _ in range(N + 1)]
primes[0] = primes[1] = False
for i in range(2, N + 1):
    if primes[i]:
        for j in range(2 * i, N + 1, i):
            primes[j] = False


# m >= k^i を満たす最大のiを返す
def f(m, k):
    return (
        1 + f(m // k, k) if m % k == 0 else
        0
    )


# 素因数分解した結果に着目して、七五数になるパターンごとに数え上げ
C = [f(M, k) for k in range(2, N + 1) if primes[k]]
ans = (
    sum(c >= 74 for (c,) in permutations(C, 1)) +
    sum(c1 >= 24 and c2 >= 2 for (c1, c2) in permutations(C, 2)) +
    sum(c1 >= 14 and c2 >= 4 for (c1, c2) in permutations(C, 2)) +
    sum(
        c1 >= 4 and c2 >= 4 and c3 >= 2
        for (c1, c2, c3) in permutations(C, 3)
    ) // 2
)

print(ans)
