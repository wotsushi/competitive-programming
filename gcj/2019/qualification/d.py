from itertools import chain, zip_longest

T = int(input())

for x in range(1, T + 1):
    # 入力
    N, B, F = map(int, input().split())

    # 情報収集
    Y = []
    for i in range(5):
        print(
            (('0' * 2**i + '1' * 2**i) * (2**(9 - i)))[:N],
            flush=True
        )
        Y.append(input())

    # 区間 [i, r + 2**r) で故障しているすべての worker のインデックスを返す
    # a は [i, r + 2**r) の正常な worker の数
    # acc は [0, i) の正常な worker の数
    def f(i, r, a, acc):
        return (
            [i] if r == 0 and a == 0 else
            [] if r == 0 and a == 1 else
            f(
                i,
                r - 1,
                Y[r - 1][acc:(a + acc)].count('0'),
                acc
            ) +
            f(
                i + 2**(r - 1),
                r - 1,
                Y[r - 1][acc:(a + acc)].count('1'),
                acc + Y[r - 1][acc:(a + acc)].count('0')
            )
        )

    # 各半開区間[16**i, 16**(i + 1)) の正常な worker 数
    C = list(
        chain(*(
            (a0, a1)
            for a0, a1, _ in zip_longest(
                (len(y0) for y0 in Y[4].split('1') if y0),
                (len(y1) for y1 in Y[4].split('0') if y1),
                range(64),
                fillvalue=0
            )
        ))
    )
    # 各半開区間[16**i, 16**(i + 1)) に対して、 f を適用して解を求める
    ans = ' '.join(
        str(b)
        for b in list(
            chain(*(
                f(16 * i, 4, C[i], sum(C[:i]))
                for i in range(64)
            ))
        )[:B]
    )
    # 出力
    print(ans, flush=True)

    # ジャッジ
    V = int(input())
    if V == -1:
        break
