from itertools import accumulate

N, C = map(int, input().split())
x, v = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

# 初期位置から時計回り／反時計回りに移動したときの利益の最大値に関する累積値を前計算しておく
acc_l = list(
    accumulate(
        (
            V - X
            for X, V in zip(
                [0] + [C - X for X in x[::-1]],
                accumulate((0,) + v[::-1])
            )
        ),
        max
    )
)
acc_r = list(
    accumulate(
        (
            V - X
            for X, V in zip(
                (0,) + x,
                accumulate((0,) + v)
            )
        ),
        max
    )
)
# 時計回りに移動した後に、反時計回りに移動 または
# 反時計回りに移動した後に、時計回りに移動 のどちらかの戦略に限ってよい
ans = max(
    max(
        V - 2 * X + acc_l[N - i]
        for i, X, V in zip(
            range(N + 1),
            (0,) + x,
            accumulate((0,) + v)
        )
    ),
    max(
        V - 2 * X + acc_r[N - i]
        for i, X, V in zip(
            range(N + 1),
            [0] + [C - X for X in x[::-1]],
            accumulate((0,) + v[::-1])
        )
    )
)

print(ans)
