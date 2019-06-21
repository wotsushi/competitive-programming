# 入力
N = int(input())

# N = 1 + 2 + ... + K で表せるならばYes
K = next(
    (
        k
        for k in range(1, N + 1)
        if k * (k + 1) // 2 == N
    ),
    0
)

# (1, 2, ..., K), (1, K + 1, ..., 2K - 1), (2, K + 1, 2K, ..., 3K - 3), ...
# を構築する
ans = (
    'Yes\n{}\n{}'.format(
        K + 1,
        '\n'.join(
            '{} {}'.format(
                K,
                ' '.join(
                    map(
                        str,
                        [
                            i + j * K - j * (j + 1) // 2
                            for j in range(i)
                        ] +
                        [
                            1 + j + i * (2 * K - (i - 1)) // 2
                            for j in range(K - i)
                        ]
                    )
                )
            )
            for i in range(K + 1)
        )
    ) if K else
    'No'
)

# 出力
print(ans)
