s = input()

S = '0' + s
N = len(s)


# 葉から順に構築
def f():
    res = []
    r = 1
    C = []
    for i in range(2, N + 1):
        if S[i] == '0':
            C.append(i)
        else:
            res.append((r, i))
            r = i
            for c in C:
                res.append((r, c))
            C = []
    for c in C:
        res.append((r, c))
    return res


ans = (
    '-1' if S[1] == '0' or S[N] == '1' or any(
        S[i] != S[N - i]
        for i in range(1, N)
    ) else
    '\n'.join(
        '{} {}'.format(u, v)
        for u, v in f()
    )
)

print(ans)
