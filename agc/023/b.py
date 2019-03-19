# 入力
N = int(input())
S = [list(input()) for _ in range(N)]

# 解は、B = 0として、A = 0, 1, ..., N - 1 のうち、よい盤面になるものの個数のN倍
ans = N * sum(
    all(
        S[i][j] == S[(j - A) % N][(i + A) % N]
        for i in range(N)
        for j in range(N)
    )
    for A in range(N)
)

# 出力
print(ans)
