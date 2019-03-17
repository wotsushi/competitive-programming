from itertools import accumulate

# 入力
Q = int(input())
l, r = zip(*(map(int, input().split()) for _ in range(Q)))

# エラトステネスのふるいにより、素数表を作成する
is_prime = [i >= 2 for i in range(10**5 + 1)]
for i in range(2, 10**5 + 1):
    if is_prime[i]:
        for j in range(2 * i, 10**5 + 1, i):
            is_prime[j] = False

# i以下の2017に似た数の累積和を求める
dp = list(
    accumulate(
        range(10**5 + 1),
        lambda acc, i: (
            acc + 1 if is_prime[i] and is_prime[(i + 1) // 2] else
            acc
        )
    )
)

# 累積和を用いて各クエリに回答する
ans = '\n'.join(
    map(
        str,
        (dp[b] - dp[a - 1] for a, b in zip(l, r))
    )
)

# 出力
print(ans)
