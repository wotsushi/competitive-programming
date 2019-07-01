from heapq import heappush, heappop

N, M = map(int, input().split())
A, B = (
    zip(*(map(int, input().split()) for _ in range(M))) if M else
    ((), ())
)
S, T = map(int, input().split())

# 拡張グラフにダイクストラ法を適用し最適解を求める
G = [{} for _ in range(3 * N + 1)]
for x, y in zip(A, B):
    G[x][y + N] = 1
    G[x + N][y + 2 * N] = 1
    G[x + 2 * N][y] = 1
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


dp = dijkstra(G, S)
ans = (
    -1 if dp[T] == INF else
    dp[T] // 3
)

print(ans)
