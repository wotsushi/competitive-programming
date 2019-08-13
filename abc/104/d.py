from functools import reduce

S = input()

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


# 動的計画法による。すなわち、
# i文字目までのA数, AB数, ABC数を求め、それらを用いて
# N文字目までのABC数を求める
_, _, _, ans = reduce(
    lambda acc, c: (
        (
            3 * acc[0] if c == '?' else
            acc[0]
        ),
        (
            acc[0] + acc[1] if c == 'A' else
            3 * acc[1] + acc[0] if c == '?' else
            acc[1]
        ),
        (
            acc[1] + acc[2] if c == 'B' else
            3 * acc[2] + acc[1] if c == '?' else
            acc[2]
        ),
        (
            acc[2] + acc[3] if c == 'C' else
            3 * acc[3] + acc[2] if c == '?' else
            acc[3]
        ),
    ),
    S,
    (ModInt(1), ModInt(0), ModInt(0), ModInt(0))
)

print(ans)
