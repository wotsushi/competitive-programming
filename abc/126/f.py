# 入力
M, K = map(int, input().split())

# K 0 1 2 ... (2**M - 1) K (2**M - 1) ... 2 1 0 が解
ans = (
    '-1' if K >= 2**M or M == K == 1 else
    '0 0' if M == 0 else
    '0 0 1 1' if M == 1 else
    '{} {} {} {}'.format(
        K,
        ' '.join(
            str(i)
            for i in range(2**M)
            if i != K
        ),
        K,
        ' '.join(
            str(i)
            for i in range(2**M - 1, -1, -1)
            if i != K
        ),
    )
)

# 出力
print(ans)
