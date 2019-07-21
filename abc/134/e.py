from bisect import bisect_left

N = int(input())
A = [int(input()) for _ in range(N)]

# 解は最長非増加部分列の長さ
dp = [-1 for _ in range(N)]
for a in A:
    dp[bisect_left(dp, a) - 1] = a
ans = sum(x >= 0 for x in dp)

print(ans)
