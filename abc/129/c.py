# 入力
N, M = map(int, input().split())
a = [int(input()) for _ in range(M)]

MOD = 10**9 + 7
A = set(a)

# i段目までにたどりつく方法を順に求める
dp = [0 for _ in range(N + 1)]
dp[0] = 1
dp[1] = int(1 not in A)
for i in range(2, N + 1):
    if i not in A:
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD
ans = dp[N]

# 出力
print(ans)
