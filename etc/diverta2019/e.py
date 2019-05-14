from itertools import accumulate
from operator import xor

# 入力
N = int(input())
A = list(map(int, input().split()))

MOD = 10**9 + 7

# 累積和が X, 0, X, 0, ... となるような数列の分割方法を数え上げて解を求める
acc = list(accumulate(A, xor))
M = max(acc)
# dp[x][0] は x, 0, x, 0, ..., x(xで終わる) となる分割方法の数
# dp[x][1] は x, 0, x, 0, ..., x, 0(0で終わる) となる分割方法の数
# dp[x][2] は 最後に x が出現したとき、それより前に出現した0の個数
# ただし、dp[x][1] は遅延評価する（0が出現するたびに再計算はしない）
dp = [[0, 0, 0] for _ in range(M + 1)]
z = 0
for x in acc:
    if x == 0:
        z += 1
    else:
        dp[x][1] = (dp[x][1] + (z - dp[x][2]) * dp[x][0]) % MOD
        dp[x][0] = (dp[x][0] + dp[x][1] + 1) % MOD
        dp[x][2] = z
for x in range(1, M + 1):
    dp[x][1] = (dp[x][1] + (z - dp[x][2]) * dp[x][0]) % MOD
ans = (
    dp[acc[-1]][1] + 1 if acc[-1] != 0 else
    sum(dp[x][0] for x in range(1, M + 1)) + pow(2, acc.count(0) - 1, MOD)
) % MOD

# 出力
print(ans)
