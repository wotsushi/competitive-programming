from functools import lru_cache
import sys
sys.setrecursionlimit(2*10**5)

# 入力
N, Z, W = map(int, input().split())
a = list(map(int, input().split()))


# バックトラック法により解を求める関数。i=1のとき、Xの手番、i=-1のときYの手番
@lru_cache(maxsize=None)
def f(i, m):
    return (
        max(
            abs(W - a[-1]) if m == N else abs(a[-(m + 1)] - a[-1]),
            max(f(-i, k) for k in range(1, m))
        ) if i == 1 and m >= 2 else
        min(
            abs(a[-(m + 1)] - a[-1]),
            min(f(-i, k) for k in range(1, m))
        ) if i == -1 and m >= 2 else
        abs(a[-2] - a[-1]) if N >= 2 else
        abs(W - a[-1])
    )


# 出力
ans = f(1, N)
print(ans)
