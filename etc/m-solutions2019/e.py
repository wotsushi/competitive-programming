# 入力
Q = int(input())
x, d, n = (
    zip(*(map(int, input().split()) for _ in range(Q))) if Q else
    ((), (), ())
)

MOD = 1000003


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


# MOD未満の整数について、階乗を求めておく
# 各クエリに対して、d^n * (x/d + (n - 1))! / ((x/d) - 1)! を回答する
f = [0 for _ in range(MOD)]
f[0] = ModInt(1)
for i in range(1, MOD):
    f[i] = i * f[i - 1]


def q(X, D, N):
    Y = (
        0 if D.x == 0 else
        X / D
    )
    return (
        X**N if D.x == 0 else
        D**N * f[Y.x + N - 1] / f[Y.x - 1] if Y.x + N - 1 < MOD else
        0
    )


ans = '\n'.join(
    str(q(X, D, N))
    for X, D, N in zip(map(ModInt, x), map(ModInt, d), n)
)

# 出力
print(ans)
