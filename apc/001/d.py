from itertools import groupby

# 出力
N, M = map(int, input().split())
a = list(map(int, input().split()))
x, y = (
    zip(*(map(int, input().split()) for _ in range(M))) if M else
    ((), ())
)


class UnionFindTree:
    def __init__(self, n):
        self.p = [i for i in range(n + 1)]
        self.r = [0 for _ in range(n + 1)]

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px != py:
            if self.r[px] < self.r[py]:
                self.p[px] = py
            else:
                self.p[py] = px
                if self.r[px] == self.r[py]:
                    self.r[px] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)


# 各連結成分のうち、a_iが最小の頂点は必ず使う
# 不足している分はa_iが小さい頂点から順に補えばよい
uft = UnionFindTree(N - 1)
for X, Y in zip(x, y):
    uft.union(X, Y)

C = [
    sorted(c, key=lambda i: a[i])
    for _, c in groupby(
        sorted(range(N), key=uft.find),
        uft.find
    )
]

K = 2 * (len(C) - 1)
S = {c[0] for c in C}

ans = (
    'Impossible' if K > N else
    0 if K == 0 else
    sum(a[s] for s in S) +
    sum(sorted(a[i] for i in range(N) if i not in S)[:(K - len(C))])
)

# 出力
print(ans)
