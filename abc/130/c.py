# 入力
W, H, x, y = map(int, input().split())

# 面積は必ず二等分可能
# 面積を二等分する直線は長方形の中心を通る
ans = '{} {}'.format(
    W * H / 2,
    1 if x == W / 2 and y == H / 2 else
    0
)

# 出力
print(ans)
