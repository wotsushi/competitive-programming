from collections import Counter
from functools import lru_cache
import sys
sys.setrecursionlimit(2*10**5)

# 入力
N, M, Q = map(int, input().split())
L, R = zip(*(map(int, input().split()) for _ in range(M)))
p, q = zip(*(map(int, input().split()) for _ in range(Q)))

# 各区間を走る列車の本数
c = Counter(zip(L, R))


# 走る区間が区間 [x, y] に含まれる列車の本数
@lru_cache(maxsize=None)
def f(x, y):
    return (
        0 if x > y else
        c[x, y] + f(x + 1, y) + f(x, y - 1) - f(x + 1, y - 1)
    )


# 各クエリに対してfを用いて回答
ans = '\n'.join(map(str, (f(x, y) for x, y in zip(p, q))))

# 出力
print(ans)
