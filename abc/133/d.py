from itertools import accumulate

N = int(input())
A = list(map(int, input().split()))

# x_1 = (A_1 - A_2 + A_3 - A_4 + ... + A_N) / 2 である
# x_2 以降は代入しながら求めればよい
ans = ' '.join(
    str(2 * x)
    for x in accumulate(
        [(sum(A[::2]) - sum(A[1::2])) // 2] + A[:-1],
        lambda acc, a: a - acc
    )
)

print(ans)
