# 入力
N, A, B = map(int, input().split())
X = list(map(int, input().split()))

# 町1, 町2, ..., 町Nの順に訪問する
ans = sum(
    min(A * (r - l), B)
    for l, r in zip(X, X[1:])
)

# 出力
print(ans)
