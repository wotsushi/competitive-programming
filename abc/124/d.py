from itertools import groupby, accumulate

# 入力
N, K = map(int, input().split())
S = input()

# 連続する0または1の数に関する累積和
A = list(accumulate(len(list(seq)) for _, seq in groupby(S))) + [N]
m = (
    1 if S[0] == '0' else
    0
)
# 累積和を用いて解を求める
ans = max(
    A[min(2 * K - 1, len(A) - 1)],
    A[-1] - A[max(-(2 * K), -len(A))],
    max(
        (
            a - b
            for a, b in zip(A[(2 * K + m)::2], ([0] + A)[m::2])
        ),
        default=0
    )
)

# 出力
print(ans)
