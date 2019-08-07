from heapq import heappush, heappop

N, M = map(int, input().split())
A, B = (
    zip(*(map(int, input().split()) for _ in range(N - 1))) if N - 1 else
    ((), ())
)
C = list(map(int, input().split()))


G = [set() for _ in range(N + 1)]
for x, y in zip(A, B):
    G[x].add(y)
    G[y].add(x)
INF = 10**10


def tree(G, r):
    p = [i for i in range(len(G))]
    c = [set() for _ in range(len(G))]
    q = []
    c[r] = G[r]
    q.append(r)
    while q:
        i = q.pop()
        for j in G[i]:
            if j != p[i]:
                p[j] = i
                c[j] = G[j] - {i}
                q.append(j)
    return p, c


def dijkstra(G, s):
    dp = [INF for _ in range(len(G))]
    q = []
    heappush(q, (0, s))
    while q:
        c, i = heappop(q)
        if dp[i] == INF:
            dp[i] = c
            for j in G[i]:
                heappush(q, (c + 1, j))
    return dp


# 頂点1を根とする木において、写真がある頂点のうち深さが最大の頂点をrとする
S = set(C)
dp1 = dijkstra(G, 1)
r = max((i for i in range(1, N + 1) if i in S), key=lambda i: dp1[i])
# 頂点rを根とする木において、写真がある頂点のうち、深さが最大の頂点をxとし、
# パス r -> x に、C_1, ..., C_N が含まれるか判定
p, _ = tree(G, r)
dpr = dijkstra(G, r)
x = max((i for i in range(1, N + 1) if i in S), key=lambda i: dpr[i])
path = {x}
i = x
while i != r:
    i = p[i]
    path.add(i)
ans = (
    'Yes' if all(c in path for c in C) else
    'trumpet'
)

print(ans)
