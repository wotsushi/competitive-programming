import sys
from functools import lru_cache

sys.setrecursionlimit(2*10**5)

# 入力
N, Ma, Mb = map(int, input().split())
a, b, c = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)


# タイプAがxグラム, タイプBがyグラムの物質の最小生成コストを動的計画法により求める
@lru_cache(maxsize=None)
def f(i, x, y):
    return (
        10**18 if (i < 0 and not (x == y == 0)) or x < 0 or y < 0 else
        0 if x == 0 and y == 0 else
        min(
            f(i - 1, x - a[i - 1], y - b[i - 1]) + c[i - 1],
            f(i - 1, x, y)
        )
    )


# タイプAとタイプBの物質の比率がMa:Mbとなるような物質の最小コストを求める
A = sum(a)
B = sum(b)
opt = min(
    f(N, x, Mb * (x // Ma))
    for x in range(Ma, A + 1)
    if x % Ma == 0 and Mb * (x // Ma) <= B
)
ans = (
    opt if opt < 10**18 else
    -1
)

# 出力
print(ans)
