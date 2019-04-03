from functools import reduce

# 入力
T = int(input())
D, P = zip(*((int(d), p) for d, p in (input().split() for _ in range(T))))


# 貪欲法により解を求める
def f(d, p, y):
    dmg, _ = reduce(
        lambda acc, c: (
            acc[0] + acc[1] if c == 'S' else acc[0],
            acc[1] if c == 'S' else 2 * acc[1]
        ),
        p,
        (0, 1)
    )
    i = next(
        (
            i
            for i in range(len(p) - 1, 0, -1)
            if p[i - 1] + p[i] == 'CS'
        ),
        0
    )
    return (
        y if dmg <= d else
        f(d, p[:(i - 1)] + p[i] + p[i - 1] + p[i + 1:], y + 1) if i > 0 else
        'IMPOSSIBLE'
    )


ans = '\n'.join(
    'Case #{}: {}'.format(x, y)
    for x, y in enumerate(
        (f(d, p, 0) for d, p in zip(D, P)),
        1
    )
)

# 出力
print(ans)
