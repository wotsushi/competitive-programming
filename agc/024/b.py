from functools import reduce

# 入力
N = int(input())
P = [int(input()) for _ in range(N)]

INF = 10**15

# Pの逆写像
Q = {p: i for i, p in enumerate(P, 1)}

# j以上の整数を末尾に移動する場合に、先頭に移動すべき整数の個数を求める
ans, _ = reduce(
    lambda acc, j: (
        min(
            acc[0],
            acc[1] + N - j + 1
        ),
        acc[1] if j > N or Q[j - 1] < Q[j] else
        j - 1
    ),
    range(2, N + 2),
    (INF, 0)
)

# 出力
print(ans)
