from math import factorial

# 入力
N, A, B = map(int, input().split())
v = list(map(int, input().split()))

u = sorted(v, reverse=True)
m = sum(x == u[A - 1] for x in v)


# 非負の整数n, k について、二項係数nCkを返す関数
def c(n, k):
    return factorial(n) // (factorial(n - k) * factorial(k))


# 平均の最大値は価値の高いものから順にA個選んだときの平均値
# そのような選び方は二項係数を用いて求める
ans = '{}\n{}'.format(
    sum(u[:A]) / A,
    (
        c(
            m,
            A - sum(x > u[A - 1] for x in v)
        ) if u[A - 1] < u[0] else
        sum(
            c(m, k)
            for k in range(A, min(m + 1, B + 1))
        )
    )
)

# 出力
print(ans)
