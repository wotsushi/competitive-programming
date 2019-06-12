from fractions import Fraction
from math import ceil, floor

# 入力
K = int(input())

# N = 50で決め打ち。操作回数がなるべく均等となるようにaを定める。
N = 50
a = [
    ceil(Fraction(K, N)) * (N + 1) + N - (K + 1)
    for _ in range(K % N)
] + [
    floor(Fraction(K, N)) * (N + 1) + N - (K + 1)
    for _ in range(N - K % N)
]
ans = '{}\n{}'.format(N, ' '.join(map(str, a)))

# 出力
print(ans)
