from functools import lru_cache

H, W, K = map(int, input().split())

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


# 長さiの横幅に対して、隣り合わないように横線を引くパターン数
@lru_cache(maxsize=None)
def f(i):
    return (
        ModInt(1) if i <= 0 else
        ModInt(2) if i == 1 else
        f(i - 1) + f(i - 2)
    )


# 動的計画法により解を求める
@lru_cache(maxsize=None)
def g(i, j):
    return (
        ModInt(0) if i == 0 and j >= 2 or j == 0 or j == W + 1 else
        ModInt(1) if i == 0 and j == 1 else
        (
            g(i - 1, j - 1) * f(j - 3) * f(W - j - 1) +
            g(i - 1, j) * f(j - 2) * f(W - j - 1) +
            g(i - 1, j + 1) * f(j - 2) * f(W - j - 2)
        )
    )


ans = g(H, K)

print(ans)
