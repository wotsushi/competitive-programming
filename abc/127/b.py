from itertools import accumulate
r, D, x_2000 = map(int, input().split())

ans = '\n'.join(
    [
        str(x)
        for x in accumulate(
            [x_2000] + list(range(10)),
            lambda acc, _: r * acc - D
        )
    ][1:]
)

print(ans)
