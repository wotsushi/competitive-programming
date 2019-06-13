from functools import reduce
from math import floor, ceil

# 入力
K = int(input())
A = list(map(int, input().split()))

# ラウンドKから1まで順に、子どもたちの人数として考えられる最小の値と最大の値を求める
R = reduce(
    lambda acc, a:
        acc if acc[0] > acc[1] else
        (
            a * ceil(acc[0] / a),
            a * (floor(acc[1] / a) + 1) - 1
        ),
    reversed(A),
    (2, 2)
)
ans = (
    -1 if R[0] > R[1] else
    ' '.join(map(str, R))
)

# 出力
print(ans)
