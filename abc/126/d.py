from heapq import heappush, heappop

# 入力
N = int(input())
u, v, w = (
    zip(*(map(int, input().split()) for _ in range(N - 1))) if (N - 1) else
    ((), (), ())
)

# 頂点1からの距離が偶数である頂点は白、奇数である頂点は黒で塗る
G = [{} for _ in range(N + 1)]
for x, y, c in zip(u, v, w):
    G[x][y] = c
    G[y][x] = c
INF = 10**18


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


dp = dijkstra(G, 1)
ans = '\n'.join(
    str(dp[i] % 2)
    for i in range(1, N + 1)
)

# 出力
print(ans)
