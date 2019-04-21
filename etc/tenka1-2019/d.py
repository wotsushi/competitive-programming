from math import ceil

# 入力
N = int(input())
A = [int(input()) for i in range(N)]

MOD = 998244353


S = sum(A)
# 赤色の整数の和がiとなるような塗り方の個数
dp = [0 for _ in range(S + 1)]
dp[0] = 1
# 赤色の整数の和がi, 他の整数がすべて青色となるような塗り方の個数
dp2 = [0 for _ in range(S // 2 + 1)]
dp2[0] = 1

# 動的計画法により、dp, dp2を求める
for a in A:
    for i in range(S, a - 1, -1):
        dp[i] = (2 * dp[i] + dp[i - a]) % MOD
    for i in range(a - 1, -1, -1):
        dp[i] = (2 * dp[i]) % MOD
    for i in range(S // 2, a - 1, -1):
        dp2[i] = (dp2[i] + dp2[i - a]) % MOD

# 全ての塗り方の個数から、条件を満たさない塗り方の個数を差し引いて解を求める
ans = (3**N - 3 * sum(dp[ceil(S / 2):]) + (
    3 * dp2[S // 2] if S % 2 == 0 else
    0
)) % MOD

# 出力
print(ans)
