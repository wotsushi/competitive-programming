# 入力
N, x = map(int, input().split())
a = list(map(int, input().split()))

# dp[i][j] は a_i, a_{i + 1}, ..., a_{j} の最小値
dp = [[0 for _ in range(N)] for i in range(N)]
for i in range(N):
    dp[i][i] = a[i]
    for k in range(1, N):
        j = (i + k) % N
        dp[i][j] = min(dp[i][(j - 1) % N], a[j])

# 変色回数を0からN-1まで決め打ちして解を求める
ans = min(
    sum(dp[i][(i + k) % N] for i in range(N)) + k * x
    for k in range(N)
)

# 出力
print(ans)
