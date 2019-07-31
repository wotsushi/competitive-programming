import sys
sys.setrecursionlimit(2 * 10**5)

N = int(input())
h = list(map(int, input().split()))


# 貪欲に極大区間に対して水やりする
def f(y):
    L = next(
        (
            i
            for i, x in enumerate(y)
            if x > 0
        ),
        N
    )
    R = next(
        (
            i
            for i, x in enumerate(y[L:], L)
            if x == 0
        ),
        N
    )
    return (
        0 if L == N else
        1 + f(
            [x for x in y[:L]] +
            [x - 1 for x in y[L:R]] +
            [x for x in y[R:]]
        )
    )


ans = f(h)

print(ans)
