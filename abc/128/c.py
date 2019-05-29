from itertools import product

# 入力
N, M = map(int, input().split())
k, s = zip(
    *(
        (k, s)
        for _ in range(M)
        for k, *s in [map(int, input().split())]
    )
)
p = list(map(int, input().split()))

# 全探索で解を求める
ans = sum(
    all(
        sum(t[j - 1] for j in S) % 2 == P
        for S, P in zip(s, p)
    )
    for t in product(range(2), repeat=N)
)

# 出力
print(ans)
