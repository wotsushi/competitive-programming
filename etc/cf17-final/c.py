from itertools import product, combinations

# 入力
N = int(input())
D = list(map(int, input().split()))

# N >= 24 ならば鳩の巣原理より、max(s)=0である
# N <= 23 ならば全探索で解を求める
ans = (
    0 if N >= 24 else
    int(
        (0 not in D) and
        (D.count(12) <= 1) and
        all(
            D.count(i) <= 2
            for i in range(1, 12)
        )
    ) if 12 <= N < 24 else
    max(
        min(
            min(abs(a - b), 24 - abs(a - b))
            for a, b in combinations(t, 2)
        )
        for t in (
            product(
                (0,),
                *(
                    (d, 24 - d)
                    for d in D
                )
            )
        )
    )
)

# 出力
print(ans)
