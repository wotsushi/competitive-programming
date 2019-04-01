from collections import defaultdict

# 入力
N = int(input())
A = list(map(int, input().split()))

# dp[s]: A_1 + ... + A_i = s となるような i の個数
dp = defaultdict(int, {0: 1})
# 和
s = 0
# 解
ans = 0
# 各iについて、 A_1 + ... + A_i = A_1 + ... + A_j となるような 0 <= j < N の個数を求める
for a in A:
    s += a
    ans += dp[s]
    dp[s] += 1

# 出力
print(ans)
