from heapq import heappush, heappop
from operator import itemgetter

# 入力
N = int(input())
a, b = (
    zip(*(map(int, input().split()) for _ in range(N - 1))) if N - 1 else
    ((), ())
)
c = list(map(int, input().split()))

# 頂点1を根とみなす。
# 頂点1から遠い頂点から順に小さい整数を書き込む
INF = 10**10
G = [{} for _ in range(N + 1)]
for x, y in zip(a, b):
    G[x][y] = 1
    G[y][x] = 1


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
x = sorted(c)
ans = '{}\n{}'.format(
    sum(x[:-1]),
    ' '.join(
        str(d)
        for (_, _), d in sorted(
            zip(
                sorted(
                    enumerate(dp[1:]),
                    key=itemgetter(1),
                    reverse=True
                ),
                x
            )
        )
    )
)

# 出力
print(ans)
