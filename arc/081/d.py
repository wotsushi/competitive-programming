from functools import reduce

# 入力
N = int(input())
S1 = input()
S2 = input()

MOD = 1000000007


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


# (1x2)x2 と (2x1) を1ブロックとみなして、色の塗り方の組合せを数え上げる
ans, _ = reduce(
    lambda acc, s:
        (3 * acc[0], 3) if acc[1] == 0 and s[0] == s[1] else
        (6 * acc[0], 1) if acc[1] == 0 and s[0] != s[1] else
        (acc[0], 2) if acc[1] == 1 else
        (acc[0], 3) if acc[1] == 2 and s[0] == s[1] else
        (3 * acc[0], 1) if acc[1] == 2 and s[0] != s[1] else
        (2 * acc[0], 3) if acc[1] == 3 and s[0] == s[1] else
        (2 * acc[0], 1),
    zip(S1, S2),
    (ModInt(1), 0)
)

# 出力
print(ans)
