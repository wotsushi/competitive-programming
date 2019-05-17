# 入力
A, B, K = map(int, input().split())

# 出力
ans = [n for n in range(A, 0, -1) if A % n == B % n == 0][K - 1]
print(ans)
