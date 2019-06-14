# 入力
P, Q, R = map(int, input().split())

ans = P + Q + R - max(P, Q, R)

# 出力
print(ans)
