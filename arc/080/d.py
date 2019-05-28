from itertools import cycle, chain, repeat

# 入力
H, W = map(int, input().split())
N = int(input())
a = list(map(int, input().split()))

# (1, 1), (1, 2), ..., (1, W), (2, W), (2, W - 1), ..., (2, 2), (2, 1),
# (3, 1), (3, 2), ... の順で色1(1マス目), 色1(2マス目), ..., 色1(a_1マス目),
# 色2(1マス目), ..., 色2(a_2マス目), 色3(1マス目), ... と塗る
c = {
    (i, j): k
    for k, i, j in zip(
        chain(
            *(
                repeat(k, m)
                for k, m in enumerate(a, 1)
            )
        ),
        chain(
            *(
                repeat(r, W)
                for r in range(H)
            )
        ),
        cycle(
            chain(
                range(W),
                reversed(range(W)),
            )
        )
    )
}
ans = '\n'.join(
    ' '.join(
        str(c[(i, j)])
        for j in range(W)
    )
    for i in range(H)
)

# 出力
print(ans)
