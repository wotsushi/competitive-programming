# 入力
A, B, C = map(int, input().split())

# A = B = C ならば正三角形
ans = 'Yes' if A == B == C else 'No'

# 出力
print(ans)
