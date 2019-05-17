from heapq import heappush, heappop
from functools import reduce
from operator import or_

# 入力
N, M = map(int, input().split())
a, b, c = (
    zip(*(map(int, input().split()) for _ in range(M))) if M else
    ((), ())
)

# 各頂点に対してダイクストラ法により最短経路を求める
G = [{} for _ in range(N + 1)]
for x, y, w in zip(a, b, c):
    G[x][y] = w
    G[y][x] = w

INF = 10**10


def dijkstra(G, s):
    dp = [INF for _ in range(len(G))]
    q = []
    res = set()
    heappush(q, (0, s, s))
    while q:
        c, i, p = heappop(q)
        if c < dp[i]:
            dp[i] = c
            for j, w in G[i].items():
                heappush(q, (c + w, j, i))
        if c == dp[i] and i != p:
            res.add((p, i))
    return res


# 最短経路に含まれない辺の数を求める
ans = M - len(reduce(or_, (dijkstra(G, i) for i in range(1, N + 1)))) // 2

# 出力
print(ans)
