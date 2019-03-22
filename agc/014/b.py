# 入力
N, M = map(int, input().split())
A, B = zip(*(map(int, input().split()) for _ in range(M)))

# 各頂点の次数をカウント
dp = [0 for _ in range(N + 1)]
for a, b in zip(A, B):
    dp[a] += 1
    dp[b] += 1

# 全ての頂点の次数が偶数ならば解はYES
ans = 'YES' if all(dp[i] % 2 == 0 for i in range(1, N + 1)) else 'NO'

# 出力
print(ans)
