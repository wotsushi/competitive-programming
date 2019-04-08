from math import ceil

# 入力
X, Y = map(int, input().split('/'))

# N の候補
N = (
    (2 * X // Y, 2 * X // Y + 1) if 2 * X % Y == 0 else
    (ceil(2 * X / Y) - 1, ceil(2 * X / Y))
)
# M の候補
M = [
    n * (n + 1) // 2 - n * X // Y if n * X % Y == 0 else
    0
    for n in N
]
# 条件を満たすN, Mの組を出力
ans = (
    'Impossible' if all(
        m <= 0 or m > n
        for n, m in zip(N, M)
    ) else
    '\n'.join(
        '{} {}'.format(n, m)
        for n, m in zip(N, M)
        if 1 <= m <= n
    )
)

# 出力
print(ans)
