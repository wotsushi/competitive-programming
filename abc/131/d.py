from functools import reduce

# 入力
N = int(input())
A, B = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

# 〆切時刻が小さい順にgreedyに仕事を処理する
ans, _ = reduce(
    lambda acc, t:
        (
            'Yes' if acc[0] == 'Yes' and acc[1] + t[0] <= t[1] else
            'No',
            acc[1] + t[0]
        ),
    sorted(zip(A, B), key=lambda t: t[1]),
    ('Yes', 0)
)

# 出力
print(ans)
