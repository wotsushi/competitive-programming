from functools import reduce
# 入力
N, M = map(int, input().split())
A, B = zip(*(map(int, input().split()) for _ in range(N)))

# 1本あたりの値段が安い店から順に購入
ans = reduce(
    lambda acc, t: (
        acc[0] + t[0] * min(t[1], M - acc[1]),
        acc[1] + t[1]
    ) if acc[1] < M else
    acc,
    sorted(zip(A, B)),
    (0, 0)
)[0]

# 出力
print(ans)
