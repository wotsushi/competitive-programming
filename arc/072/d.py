# 入力
X, Y = map(int, input().split())

# Aliceが勝つための必要十分条件はXとYの差が2以上であること
ans = (
    'Alice' if abs(X - Y) >= 2 else
    'Brown'
)

# 出力
print(ans)
