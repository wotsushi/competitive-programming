from functools import reduce

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 小さい番号の勇者から順に小さい番号の街のモンスターを優先して倒す
ans, _ = reduce(
    lambda acc, i: (
        acc[0] + min(acc[1] + A[i + 1], B[i]),
        max(0, A[i + 1] - max(0, B[i] - acc[1]))
    ),
    range(N),
    (0, A[0])
)

print(ans)
