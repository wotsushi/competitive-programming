n, m = map(int, input().split())
u, v, s = (
    zip(*(map(int, input().split()) for _ in range(m))) if m else
    ((), (), ())
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


# 適当な全域木をもとに、頂点1に書き込める整数の範囲を求める
# その後、残っている辺について、制約に反することなく整数を書き込めるか判定する
uft = UnionFindTree(n)
E = []
E_ = []
for x, y, w in zip(u, v, s):
    if uft.same(x, y):
        E_.append((x, y, w))
    if not uft.same(x, y):
        E.append((x, y, w))
        uft.union(x, y)

G = [{} for _ in range(n + 1)]
for x, y, w in E:
    G[x][y] = w
    G[y][x] = w
dp = [None for _ in range(n + 1)]
q = [1]
dp[1] = 1
W = {1}
B = set()
while q:
    x = q.pop()
    for y, w in G[x].items():
        if dp[y] is None:
            dp[y] = w - dp[x]
            if x in W:
                B.add(y)
            else:
                W.add(y)
            q.append(y)
W_min = min(dp[x] for x in W)
B_min = min(dp[x] for x in B)

d = -1
for x, y, w in E_:
    if x in W and y in W:
        D = w - dp[x] - dp[y]
        d = (
            D // 2 if D % 2 == 0 and D >= 0 and (d == -1 or D // 2 == d) else
            None
        )
    elif x in B and y in B:
        D = dp[x] + dp[y] - w
        d = (
            D // 2 if D % 2 == 0 and D >= 0 and (d == -1 or D // 2 == d) else
            None
        )
    else:
        d = (
            d if dp[x] + dp[y] == w else
            None
        )
ans = (
    0 if d is None else
    1 if 1 - W_min <= d < B_min else
    max(0, W_min + B_min - 1)
)

print(ans)
