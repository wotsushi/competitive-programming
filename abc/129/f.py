from functools import reduce

L, A, B, M = map(int, input().split())

MOD = M


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


def iceil(a, b):
    return (a + b - 1) // b


# 等差数列を桁数が同一の要素ごとに区切る
# 区切った等差数列の各要素について、それを末尾に追加する操作を線形変換とみなす
# 線形変換はダブリングで高速に計算する
T = {}
x = A
while x <= A + B * (L - 1):
    k = len(str(x))
    r = iceil(
        min(
            10**k,
            A + B * (L - 1) + 1
        ) - x,
        B
    )
    T[k] = r
    x += r * B


def mut_mul(X, Y):
    return [
        [
            sum(X[i][k] * Y[k][j] for k in range(len(Y)))
            for j in range(len(Y[0]))
        ]
        for i in range(len(X))
    ]


def mut_pow(X, n):
    if n == 0:
        return [
            [1, 0, 0],
            [0, 1, 0],
            [0, 0, 1]
        ]
    else:
        Y = mut_pow(X, n // 2)
        return (
            mut_mul(Y, Y) if n % 2 == 0 else
            mut_mul(mut_mul(Y, Y), X)
        )


def f(p, q, k, r):
    Y = mut_pow(
        [
            [ModInt(10**k), ModInt(1), ModInt(0)],
            [ModInt(0), ModInt(1), ModInt(1)],
            [ModInt(0), ModInt(0), ModInt(1)]
        ],
        r
    )
    Z = mut_mul(
        Y,
        [
            [p],
            [q],
            [ModInt(B)]
        ]
    )
    return (Z[0][0], Z[1][0])


ans, _ = reduce(
    lambda acc, kr: f(acc[0], acc[1], kr[0], kr[1]),
    sorted(T.items()),
    (ModInt(0), ModInt(A))
)

print(ans)
