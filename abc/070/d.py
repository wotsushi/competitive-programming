from heapq import heappush, heappop

# 入力
N = int(input())
a, b, c = (
    zip(*(map(int, input().split()) for _ in range(N - 1))) if N else
    ((), ())
)
Q, K = map(int, input().split())
x, y = (
    zip(*(map(int, input().split()) for _ in range(Q))) if Q else
    ((), ())
)

# K から各頂点への最短距離を求める。
INF = 10**18

G = [{} for _ in range(N + 1)]
for u, v, w in zip(a, b, c):
    G[u][v] = w
    G[v][u] = w


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


dp = dijkstra(G, K)

# j 番目のクエリの解は dp[x_j] + dp[y_j] である
ans = '\n'.join(
    str(dp[i] + dp[j])
    for i, j in zip(x, y)
)

# 出力
print(ans)
