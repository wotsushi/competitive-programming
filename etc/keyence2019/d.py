from functools import reduce
from collections import Counter

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

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


# NMから順に配置可能なセルの個数を数え上げる
# ポイント: セルの縦横サイズと、これまでにいくつの数字を書き込んだかを覚えておくだけで数え上げ可能
a = Counter(A)
b = Counter(B)
ans, _, _ = reduce(
    lambda acc, k:
        (0, 0, 0) if a[k] >= 2 or b[k] >= 2 else
        (acc[0], acc[1] + 1, acc[2] + 1) if a[k] == b[k] == 1 else
        (acc[0] * acc[1], acc[1], acc[2] + 1) if a[k] == 1 and b[k] == 0 else
        (acc[0] * acc[2], acc[1] + 1, acc[2]) if a[k] == 0 and b[k] == 1 else
        (acc[0] * (acc[1] * acc[2] - (N * M - k)), acc[1], acc[2]),
    range(N * M, 0, -1),
    (ModInt(1), ModInt(0), ModInt(0))
)

print(ans)
