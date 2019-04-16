# 入力
N = int(input())
A = [int(input()) for _ in range(N)]

B = sorted(A)

# (中央値、最小値, 最大値, 2番目の最小値, 2番目の最大値, ...) の順で差をとる場合と、
# (中央、最大値, 最小値, 2番目の最大値, 2番目の最小値, ...) の順で差をとる場合を比較し、
# 大きい方を解とする
ans = (
    2 * sum(
        B[-(i + 1)] - B[i]
        for i in range(N // 2)
    ) - min(
        B[N // 2] - B[N // 2 - 1],
        B[N // 2 + 1] - B[N // 2] if N % 2 == 1 else 10**18
    )
)
# 出力
print(ans)
