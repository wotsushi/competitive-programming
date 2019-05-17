# 入力
n, m = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

# i番目の直線とi-1番目の直線の間の領域が使用される回数をもとに解を求める
ans = (
    sum(i * (n - i) * (x[i] - x[i - 1]) for i in range(1, n)) *
    sum(i * (m - i) * (y[i] - y[i - 1]) for i in range(1, m))
) % (10**9 + 7)

# 出力
print(ans)
