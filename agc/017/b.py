# 入力
N, A, B, C, D = map(int, input().split())

# 左から右を引いた値が非負であるものの個数がm とすると負であるものの個数を N - 1 - m である。
# 各 m について一番右にBをかけるか判定する
ans = (
    'YES' if any(
        A + C * m - D * (N - 1 - m) <= B <= A + D * m - C * (N - 1 - m)
        for m in range(N)
    ) else
    'NO'
)

# 出力
print(ans)
