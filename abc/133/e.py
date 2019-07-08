from functools import reduce

N, K = map(int, input().split())
a, b = (
    zip(*(map(int, input().split()) for _ in range(N - 1))) if N - 1 else
    ((), ())
)

MOD = 10**9 + 7


class ModInt:
    def __init__(self, x):
        self.x = x % MOD

    def __str__(self):
        return str(self.x)

    __repr__ = __str__

    def __add__(self, other):
        return (
            ModInt(self.x + other.x) if isinstance(other, ModInt) else
            ModInt(self.x + other)
        )

    def __sub__(self, other):
        return (
            ModInt(self.x - other.x) if isinstance(other, ModInt) else
            ModInt(self.x - other)
        )

    def __mul__(self, other):
        return (
            ModInt(self.x * other.x) if isinstance(other, ModInt) else
            ModInt(self.x * other)
        )

    def __truediv__(self, other):
        return (
            ModInt(
                self.x * pow(other.x, MOD - 2, MOD)
            ) if isinstance(other, ModInt) else
            ModInt(self.x * pow(other, MOD - 2, MOD))
        )

    def __pow__(self, other):
        return (
            ModInt(
                pow(self.x, other.x, MOD)
            ) if isinstance(other, ModInt) else
            ModInt(pow(self.x, other, MOD))
        )

    def __radd__(self, other):
        return ModInt(other + self.x)

    def __rsub__(self, other):
        return ModInt(other - self.x)

    def __rmul__(self, other):
        return ModInt(other * self.x)

    def __rtruediv__(self, other):
        return ModInt(other * pow(self.x, MOD - 2, MOD))

    def __rpow__(self, other):
        return ModInt(pow(other, self.x, MOD))


G = [{} for _ in range(N + 1)]
for x, y in zip(a, b):
    G[x][y] = 1
    G[y][x] = 1
INF = 10**9


def p(n, r):
    return reduce(
        lambda acc, i: acc * (n - i),
        range(r),
        ModInt(1)
    )


# 頂点iの次数をd_iで表すとき、
# 解は K * (K-1)P(d_1) * (K-2)P(d_2-1) * (K-2)P(d_3-1) * ... * (K-2)P(d_N-1) である
ans = reduce(
    lambda acc, i: acc * p(K - 2, len(G[i]) - 1),
    range(2, N + 1),
    K * p(K - 1, len(G[1]))
)

print(ans)
