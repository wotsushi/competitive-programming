from itertools import islice

# 入力
N, K = map(int, input().split())

# スターグラフに適当に辺を追加する
S = (N - 1) * (N - 2) // 2
D = S - K

ans = (
    -1 if K > S else
    '{}\n{}'.format(
        (N - 1) + D,
        '\n'.join(
            '{} {}'.format(u, v)
            for u, v in [
                (1, i)
                for i in range(2, N + 1)
            ] + [
                (u, v)
                for u, v in islice(
                    (
                        (x, y)
                        for x in range(2, N + 1)
                        for y in range(x + 1, N + 1)
                    ),
                    D
                )
            ]
        )
    )
)

# 出力
print(ans)
