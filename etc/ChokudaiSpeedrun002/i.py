from fractions import Fraction
from math import ceil

# 入力
N = int(input())
A, B = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

# 食べ物iが最強の食べ物ならば食べ物iはABが最大となる食べ物
# であることを利用して解を探索する
p = [a * b for a, b in zip(A, B)]
m = max(p)
w, *v = [i for i, q in enumerate(p) if q == m]
ans = (
    w + 1 if not v and all(
        A[w] > b * ceil(Fraction(a, B[w]))
        for i, (a, b) in enumerate(zip(A, B))
        if i != w
    ) else
    -1
)

# 出力
print(ans)
