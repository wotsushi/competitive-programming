from functools import reduce

S = input()

# 末尾から各あまりについてDP
M = 13
MOD = 10**9 + 7
ans = reduce(
    lambda acc, c: (
        [
            sum(
                acc[0][(i - acc[1] * j) % M]
                for j in range(10)
            ) % MOD
            for i in range(M)
        ] if c == '?' else
        [
            acc[0][(i - acc[1] * int(c)) % M]
            for i in range(M)
        ],
        (10 * acc[1]) % M
    ),
    S[::-1],
    (
        [
            1 if i == 0 else
            0
            for i in range(M)
        ],
        1
    )
)[0][5]

print(ans)
