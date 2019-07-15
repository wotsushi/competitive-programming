from heapq import heappush, heappop

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


# Mが奇数ならば構築不可
# Mが偶数ならば適当に木を構築し、深さの大きい頂点を端点とする辺から向きを決めていく
utf = UnionFindTree(N)
T = [{} for _ in range(N + 1)]
for a, b in zip(A, B):
    if not utf.same(a, b):
        T[a][b] = 1
        T[b][a] = 1
        utf.union(a, b)
INF = 10**9


def dijkstra(G, s):
    dp = [INF for _ in range(len(G))]
    q = []
    heappush(q, (0, s))
    while q:
        c, i = heappop(q)
        if dp[i] == INF:
            dp[i] = c
            for j, w in G[i].items():
                heappush(q, (c + w, j))
    return dp


r = dijkstra(T, 1)
p = [0, 1] + [
    min(T[i], key=lambda j: r[j])
    for i in range(2, N + 1)
]
dp = [0 for _ in range(N + 1)]
for a, b in zip(A, B):
    if b not in T[a]:
        dp[a] += 1
for i in sorted(
        range(1, N + 1),
        key=lambda j: r[j],
        reverse=True
):
    dp[i] += sum(
        (dp[j] + 1) % 2
        for j in T[i]
        if j != p[i]
    )
ans = (
    -1 if M % 2 == 1 else
    '\n'.join(
        '{} {}'.format(a, b)
        if b not in T[a] or (
            dp[a] % 2 == 1 and p[a] == b or
            dp[b] % 2 == 0 and p[b] == a
        ) else
        '{} {}'.format(b, a)
        for a, b in zip(A, B)
    )
)

print(ans)
