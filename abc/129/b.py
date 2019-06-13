# 入力
N = int(input())
W = list(map(int, input().split()))

# 全探索により解を求める
ans = min(
    abs(sum(W[:T]) - sum(W[T:]))
    for T in range(1, N)
)

# 出力
print(ans)
