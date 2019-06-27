# 入力
N, L = map(int, input().split())

# 絶対値が最小のリンゴを食べればよい
R = L + N - 1
S = N * (L + R) // 2
ans = S - max(0, L) - min(0, R)

# 出力
print(ans)
