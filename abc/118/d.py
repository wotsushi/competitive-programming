import sys
from functools import lru_cache
sys.setrecursionlimit(2*10**5)

# 入力
N, M = map(int, input().split())
A = list(map(int, input().split()))

INF = 10**15
# 各数字の消費マッチ棒
C = (100, 2, 5, 5, 4, 5, 6, 3, 7, 6)


# N=nのときの解に対応するベクトルを返す
@lru_cache(maxsize=None)
def dfs(n):
    return (
        [-INF for _ in range(9)] if n < 0 else
        [0 for _ in range(9)] if n == 0 else
        max(
            (
                [
                    t + 1 if i == a else t
                    for i, t in enumerate(dfs(n - C[a]), start=1)
                ]
                for a in A
            ),
            key=lambda x: [sum(x)] + list(reversed(x))
        )
    )


# 出力
ans = ''.join(str(a) * dfs(N)[a - 1] for a in sorted(A, reverse=True))
print(ans)
