# 入力
N = int(input())
x, u = zip(*((float(t[0]), t[1]) for t in (input().split() for _ in range(N))))

# 定義通り計算
ans = sum(
    t[0] if t[1] == 'JPY' else
    380000 * t[0]
    for t in zip(x, u)
)

# 出力
print(ans)
