from operator import itemgetter
from heapq import heappush, heappop

N, M, Q = map(int, input().split())
A, B, C = (
    zip(*(map(int, input().split()) for _ in range(M))) if M else
    ((), ())
)
q = [int(input()) for _ in range(Q)]


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
        if self.r[px] < self.r[py]:
            self.r[py] += self.r[px]
            self.p[px] = py
        else:
            self.r[px] += self.r[py]
            self.p[py] = px

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def size(self, x):
        return self.r[self.find(x)]


# 長さの小さい路線から順に、その路線で部屋を結合した後の結合成分サイズの度数分布を求める
# サイズがp未満の結合成分の度数が0となったときのpとその路線の長さcを記憶しておく
# 各クエリに対して、記憶した情報をもとに回答する
INF = 10**20
uft = UnionFindTree(N)
dp = [0 for _ in range(N + 1)]
dp[1] = N
i = 1
qL = [INF for _ in range(N + 1)]
qL[1] = 0
for a, b, c in sorted(zip(A, B, C), key=itemgetter(2)):
    if not uft.same(a, b):
        dp[uft.size(a)] -= 1
        dp[uft.size(b)] -= 1
        uft.union(a, b)
        dp[uft.size(a)] += 1
    while dp[i] == 0:
        i += 1
        qL[i] = c
ans = '\n'.join(
    str(qL[p]) if p <= N and qL[p] < INF else
    'trumpet'
    for p in q
)

print(ans)
