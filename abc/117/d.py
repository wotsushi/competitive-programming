# 入力
N, K = map(int, input().split())
A = list(map(int, input().split()))


# MSBから順に0or1を決めていく
# 0にする場合、下位ビットの最適値は貪欲に求まる
def s(i):
    return sum((a >> (i - 1)) & 1 for a in A)


def g(L, b):
    m = 2**(b - 1)
    return (
        0 if b == 0 else
        g(L, b - 1) + m * s(b) if L < m else
        g(L >> 1, b - 1) + m * max(
            s(b),
            N - s(b)
        ) if L == (2**b - 1) else
        max(
            g(m - 1, b - 1) + m * s(b),
            g(L - m, b - 1) + m * (N - s(b))
        )
    )


ans = g(K, max(K, *A).bit_length())

# 出力
print(ans)
