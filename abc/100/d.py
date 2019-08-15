from itertools import product

N, M = map(int, input().split())
x, y, z = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

# 綺麗さの和、おいしさの和、人気度の和の符号を決め打ちしたときの最大値を貪欲法により求める
# 解はそれらの最大値である
ans = max(
    sum(
        abs(sum(t[i] for t in ts))
        for i in range(3)
    )
    for ts in (
        sorted(
            zip(x, y, z),
            key=lambda t: sum(map(lambda st: st[0] * st[1], zip(s, t))),
            reverse=True
        )[:M]
        for s in product((1, -1), repeat=3)
    )
)

print(ans)
