from itertools import permutations

# 入力
N, C = map(int, input().split())
D = [list(map(int, input().split())) for _ in range(C)]
c = [list(map(int, input().split())) for _ in range(N)]

# (i + j) % 3 = k のマスを色cに塗り替える際の違和感の和
dp = {
    k: [
        sum(
            D[c[i][j] - 1][k - 1] if (i + j) % 3 == m else
            0
            for i in range(N)
            for j in range(N)
        )
        for m in range(3)
    ]
    for k in range(1, C + 1)
}

# dpを用いて全探索し解を得る
ans = min(
    dp[i][0] + dp[j][1] + dp[k][2]
    for i, j, k in permutations(range(1, C + 1), 3)
)

# 出力
print(ans)
