# 入力
N, M = map(int, input().split())
A, B = (
    zip(*(map(int, input().split()) for _ in range(M))) if M else
    ((), ())
)


class UnionFindTree:
    def __init__(self, n):
        self.p = [i for i in range(n + 1)]
        self.r = [1 for _ in range(n + 1)]

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
                self.r[py] += self.r[px]
            else:
                self.p[py] = px
                self.r[px] += self.r[py]

    def same(self, x, y):
        return self.find(x) == self.find(y)


# クエリを逆順に処理して不便さを求める
utf = UnionFindTree(N)
xs = []
d = N * (N - 1) // 2
for a, b in reversed(list(zip(A, B))):
    xs.append(d)
    if not utf.same(a, b):
        d -= utf.r[utf.find(a)] * utf.r[utf.find(b)]
        utf.union(a, b)
ans = '\n'.join(str(x) for x in reversed(xs))

# 出力
print(ans)
