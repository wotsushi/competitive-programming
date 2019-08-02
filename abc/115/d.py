N, X = map(int, input().split())


# 漸化式を立てて解く
def f(n, x):
    return (
        0 if x <= 0 else
        2**(n + 1) - 1 if x >= 2**(n + 2) - 3 else
        f(n - 1, x - 1) +
        f(0, x - (2**(n + 1) - 2)) +
        f(n - 1, x - (2**(n + 1) - 1))
    )


ans = f(N, X)

print(ans)
