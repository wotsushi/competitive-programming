from itertools import product

# 入力
H, W = map(int, input().split())
c = [list(map(int, input().split())) for _ in range(10)]
A = [list(map(int, input().split())) for _ in range(H)]

# 整数 i を 0 に書き換えるのに必要な魔力の最小量を求める
G = [{} for _ in range(10)]
for i, j in product(range(10), repeat=2):
    G[i][j] = c[i][j]
INF = 10**10


def warshall_floyd(G):
    dp = [
        [
            0 if i == j else
            G[i][j] if j in G[i] else
            INF
            for j in range(len(G))
        ]
        for i in range(len(G))
    ]
    for k in range(len(G)):
        for i in range(len(G)):
            for j in range(len(G)):
                dp[i][j] = (
                    dp[i][j] if dp[i][k] == INF or dp[k][j] == INF else
                    min(dp[i][j], dp[i][k] + dp[k][j])
                )
    return dp


dp = warshall_floyd(G)
# すべての数字について、dp を用いて解を求める
ans = sum(
    dp[x][1]
    for a in A
    for x in a
    if x >= 0
)

# 出力
print(ans)
