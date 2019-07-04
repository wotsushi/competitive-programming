N = int(input())
a = list(map(int, input().split()))

# 絶対値が最大の要素a_jをすべての要素に加算する。
# その後、
# a_j >= 0 ならば a_1 に a_j を加算し、a_i に a_{i - 1} を加算
# a_j < 0 ならば a_N に a_j を加算し、a_i に a_{i + 1} を加算
i = max(range(N), key=lambda j: abs(a[j])) + 1
ans = '{}\n{}'.format(
    2 * N,
    '\n'.join(
        [
            '{} {}'.format(i, j)
            for j in range(1, N + 1)
            if j != i
        ] +
        [
            '{} {}'.format(i, i)
        ] +
        (
            [
                '{} {}'.format(i, 1)
            ] +
            [
                '{} {}' .format(j, j + 1)
                for j in range(1, N)
            ] if a[i - 1] >= 0 else
            [
                '{} {}'.format(i, N)
            ] +
            [
                '{} {}'.format(j + 1, j)
                for j in reversed(range(1, N))
            ]
        )
    )
)

print(ans)
