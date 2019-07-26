S = input()

# 中央から同一の数字が何個並ぶかによって解は求まる
N = len(S)
M = N // 2
ans = M + next(
    (
        i
        for i in range(N - M)
        if (
            S[M - i - 1] != S[M] or S[M + i] != S[M] if N % 2 == 0 else
            S[M - i] != S[M] or S[M + i] != S[M]
        )
    ),
    N - M
)

print(ans)
