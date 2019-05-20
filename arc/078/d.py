from heapq import heappush, heappop

# 入力
N = int(input())
a, b = (
    zip(*(map(int, input().split()) for _ in range(N - 1))) if N - 1 else
    ((), ())
)

# 頂点1, N から各蝶点への距離を求める
G = [{} for _ in range(N + 1)]
for x, y in zip(a, b):
    G[x][y] = 1
    G[y][x] = 1
INF = 10**10


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


dp1 = dijkstra(G, 1)
dpN = dijkstra(G, N)
# 頂点Nより頂点1のほうが近い頂点、または、頂点1と頂点Nとの距離が等しい頂点は
# 頂点1から頂点Nの間のパスに含まれる頂点のうち、Fennecが塗れる頂点である。
ans = (
    'Fennec' if sum(dp1[i] <= dpN[i] for i in range(1, N + 1)) > N // 2 else
    'Snuke'
)

# 出力
print(ans)
