# 入力
N = int(input())
S, P = (
    zip(*(
        (s, int(p))
        for s, p in (input().split() for _ in range(N))
    )) if N else
    ((), ())
)

ans = '\n'.join(
    str(i)
    for _, _, i in sorted(
        zip(
            S,
            P,
            range(1, N + 1)
        ),
        key=lambda t: (t[0], -t[1])
    )
)

# 出力
print(ans)
