# 入力
N = int(input())

# Nが偶数ならば完全グラフから辺 (1, N), (2, N-1), ... を除いたグラフが解
# Nが奇数ならば完全グラフから辺 (1, N-1), (2, N-2), ... を除いたグラフが解
M = (
    N * (N - 1) // 2 - N // 2 if N % 2 == 0 else
    N * (N - 1) // 2 - (N - 1) // 2
)
s = N + 1 if N % 2 == 0 else N
ans = str(M) + '\n' + '\n'.join(
    '{} {}'.format(i, j)
    for i in range(1, N)
    for j in range(i + 1, N + 1)
    if i + j != s
)

# 出力
print(ans)
