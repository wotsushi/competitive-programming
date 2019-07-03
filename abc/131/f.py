from itertools import groupby
from operator import itemgetter

N = int(input())
x, y = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
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


# x座標またはy座標を共有する点についてグループ化する
# グループごとに可能な操作回数を求めるのは簡単
uft = UnionFindTree(N)
for d in range(2):
    for _, g in groupby(
                sorted(
                    zip(
                        x,
                        y,
                        range(1, N + 1)
                    ),
                    key=itemgetter(d)
                ),
                key=itemgetter(d)
            ):
        p = list(g)
        for (_, _, i), (_, _, j) in zip(p[1:], p):
            uft.union(i, j)
ans = sum(
    len({x for x, _, _ in C}) * len({y for _, y, _ in C}) - len(list(C))
    for C in (
        list(g)
        for _, g in groupby(
            sorted(
                (
                    (x, y, uft.find(i))
                    for x, y, i in zip(
                        x,
                        y,
                        range(1, N + 1)
                    )
                ),
                key=itemgetter(2)
            ),
            key=itemgetter(2)
        )
    )
)

print(ans)
