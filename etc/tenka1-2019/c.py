from itertools import accumulate, chain

# 入力
N = int(input())
S = input()

# 黒色の石の個数に関する累積和を求めておく
dp = list(
    accumulate(
        chain(
            [0],
            map(lambda s: s == '#', S)
        )
    )
)

# 各iについて、左i個を白色、右N-i個を黒色にする際、色を変更する必要のある石の個数を求め、
# 最小値を解とする。
ans = min(
    dp[i] + (N - i - (dp[N] - dp[i]))
    for i in range(N + 1)
)

# 出力
print(ans)
