from functools import reduce

N = int(input())
S = input()

MOD = 998244353


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


# 先頭のボールから順に、割り当て可能な人のうち最もボールを持っている人に割り当てることを繰り返す
def f(s, res, z, r, g, b, rg, gb, br):
    return (
        (
            (res * gb, z, r, g, b, rg, gb - 1, br) if gb else
            (res * g, z, r, g - 1, b, rg + 1, gb, br) if g else
            (res * b, z, r, g, b - 1, rg, gb, br + 1) if b else
            (res * z, z - 1, r + 1, g, b, rg, gb, br)
        ) if s == 'R' else
        (
            (res * br, z, r, g, b, rg, gb, br - 1) if br else
            (res * r, z, r - 1, g, b, rg + 1, gb, br) if r else
            (res * b, z, r, g, b - 1, rg, gb + 1, br) if b else
            (res * z, z - 1, r, g + 1, b, rg, gb, br)
        ) if s == 'G' else
        (
            (res * rg, z, r, g, b, rg - 1, gb, br) if rg else
            (res * r, z, r - 1, g, b, rg, gb, br + 1) if r else
            (res * g, z, r, g - 1, b, rg, gb + 1, br) if g else
            (res * z, z - 1, r, g, b + 1, rg, gb, br)
        )
    )


ans, *_ = reduce(
    lambda acc, s: f(s, *acc),
    S,
    (ModInt(1), N, 0, 0, 0, 0, 0, 0)
)

print(ans)
