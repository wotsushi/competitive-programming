from itertools import count, accumulate

A, K = map(int, input().split())

# K = 0 ならば 目標金額 - A が解
# K >= 1 ならば 所持金は指数的に増加するので、シミュレーション
X = 2 * 10**12
ans = (
    max(0, X - A) if K == 0 else
    next(
        i
        for i, acc in enumerate(
            accumulate(
                count(A),
                lambda acc, _: 1 + (K + 1) * acc
            )
        )
        if acc >= X
    )
)

print(ans)
