# 入力
N, K = map(int, input().split())
S = input()

# 出力
ans = S[:(K-1)] + S[K-1].lower() + S[K:]
print(ans)
