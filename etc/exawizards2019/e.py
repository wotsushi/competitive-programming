# 入力
B, W = map(int, input().split())

# ModInt定義
MOD = 10**9 + 7


class ModInt:
    def __init__(self, x):
        self.x = x % MOD

    def __str__(self):
        return str(self.x)

    def __repr__(self):
        return str(self.x)

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
            ModInt(pow(self.x, other.x, MOD)) if isinstance(other, ModInt) else
            ModInt(self.x * pow(other, MOD - 2, MOD))
        )

    __radd__ = __add__
    __rsub__ = __sub__
    __rmul__ = __mul__
    __rtruediv__ = __truediv__
    __rpow__ = __pow__


p = ModInt(0)
q = ModInt(0)
cp = ModInt(0)
cq = ModInt(0)
for i in range(1, B + W + 1):
    # i番目の解は i-1番目までに白チョコレートが枯渇している確率 +
    # i-1番目までにどちらのチョコレートも枯渇しない確率 / 2
    ans = (1 + q - p) / 2
    # 出力
    print(ans)
    cp = (
        ModInt(0) if i < B else
        ModInt(1) if i == B else
        cp * (i - 1) / (i - B)
    )
    p = (
        ModInt(0) if i < B else
        ModInt(1) / ModInt(2**i) if i == B else
        p + cp / pow(2, i, MOD)
    )
    cq = (
        ModInt(0) if i < W else
        ModInt(1) if i == W else
        cq * (i - 1) / (i - W)
    )
    q = (
        ModInt(0) if i < W else
        ModInt(1) / ModInt(2**i) if i == W else
        q + cq / pow(2, i, MOD)
    )
