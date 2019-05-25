# 入力
N = int(input())
s = input()
xs = [
    1 if c == 'o' else
    -1
    for c in s
]

# 動物1と動物2の種別を決め打ちで割り当てて、矛盾がないかを検証する
dp = {
    l: {
        r: [0 for _ in range(N + 2)]
        for r in (1, -1)
    }
    for l in (1, -1)
}
for l in (1, -1):
    for r in (1, -1):
        dp[l][r][0] = l
        dp[l][r][1] = r
        for i in range(2, N + 2):
            dp[l][r][i] = dp[l][r][i - 2] * dp[l][r][i - 1] * xs[(i - 1) % N]
ans = next(
    (
        ''.join(
            'S' if dp[l][r][i] == 1 else
            'W'
            for i in range(N)
        )
        for l in (1, -1)
        for r in (1, -1)
        if dp[l][r][N] == l and dp[l][r][N + 1] == r
    ),
    '-1'
)

# 出力
print(ans)
