from functools import reduce

# 入力
N = int(input())
A = [int(input()) for _ in range(N)]

# 貪欲法に基づき、小さい整数から順にペアを作成
ans, _ = reduce(
    lambda acc, a: (
        acc[0] + (a + acc[1]) // 2,
        max(0, a - acc[1]) % 2
    ),
    A,
    (0, 0)
)

# 出力
print(ans)
