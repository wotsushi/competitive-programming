from functools import reduce

# 入力
s = input()

# AA..ABC -> BCAA..A に変換するのを繰り返す
ans, _, _ = reduce(
    lambda acc, c: (
        (acc[0], (1 - acc[2]) * acc[1] + 1, 0) if c == 'A' else
        (acc[0], (1 - acc[2]) * acc[1], 1 - acc[2]) if c == 'B' else
        (acc[0] + acc[2] * acc[1], acc[2] * acc[1], 0)
    ),
    s,
    (0, 0, 0)
)

# 出力
print(ans)
