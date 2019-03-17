# 入力
N = int(input())
C = [int(input()) for _ in range(N)]

# 現時点で最も左の、色C_iの石が存在する負のインデックス（0は存在しないことを表す）
k = [0 for _ in range((2 * 10**5) + 1)]

# 動的計画法により解を求める
dp = [0 for _ in range(N)]
k[C[-1]] = -1
dp[-1] = 1
for i in range(2, N + 1):
    if k[C[-i]] == 0 or k[C[-i]] == -i + 1:
        dp[-i] = dp[-i + 1]
    else:
        dp[-i] = (dp[-i + 1] + dp[k[C[-i]]]) % (10**9 + 7)
    k[C[-i]] = -i
ans = dp[0]

# 出力
print(ans)
