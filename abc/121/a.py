# 入力
H, W = map(int, input().split())
h, w = map(int, input().split())

# 出力
ans = (H - h) * (W - w)
print(ans)
