from math import gcd
from string import ascii_uppercase
from functools import lru_cache

T = int(input())


for x in range(1, T + 1):
    # 入力
    N, L = map(int, input().split())
    C = list(map(int, input().split()))

    # plaintextの値を最初に特定できるインデックス
    k = next(i for i in range(1, L) if C[i - 1] != C[i])

    # GCDを用いて素数を特定する
    @lru_cache(maxsize=None)
    def p(i):
        return (
            C[i] // p(i + 1) if i < k else
            gcd(C[i - 1], C[i]) if i == k else
            C[i - 1] // p(i - 1)
        )

    # plaintextの各文字に対応する値
    P = list(map(p, range(L + 1)))
    # 各素数に対応するアルファベット
    A = dict(zip(sorted(set(P)), ascii_uppercase))
    # PとAを用いて復号
    y = ''.join(A.get(p, 'Z') for p in P)

    # 出力
    print('Case #{}: {}'.format(x, y))
