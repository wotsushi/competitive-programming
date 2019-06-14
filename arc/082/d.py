from functools import reduce

# 入力
N = int(input())
p = list(map(int, input().split()))

# 先頭から順にスワップする
ans = sum(
    reduce(
        lambda acc, q:
            (
                acc[0] + acc[1],
                (not acc[1]) and q
            ),
        (i == P for i, P in enumerate(p, start=1)),
        (0, 0)
    )
)

# 出力
print(ans)
