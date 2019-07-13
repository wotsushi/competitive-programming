from collections import defaultdict

N, M = map(int, input().split())
X = list(map(int, input().split()))

# Mで割った余りに着目する
# 余りがiの整数は余りがM-iの整数とペアになれる
# 余りがiである整数のコレクションをA, M-iである整数のコレクションをBとする
# |A| > |B| ならば Aの要素同士で |A| = |B| または |B| + 1 となるまでペアを作る
# |A| < |B| ならば Bの要素同士で |B| = |A| または |A| + 1 となるまでペアを作る
# その後、A, B間でペアを作ればよい
Y = [defaultdict(int) for i in range(M)]
for x in X:
    Y[x % M][x] += 1
S = [sum(s for s in y.values()) for y in Y]
ans = S[0] // 2 + sum(
    S[M - i] + min(
        sum(v // 2 for v in Y[i].values()),
        (S[i] - S[M - i]) // 2
    ) if S[i] >= S[M - i] else
    S[i] + min(
        sum(v // 2 for v in Y[M - i].values()),
        (S[M - i] - S[i]) // 2
    )
    for i in range(1, (M + 1) // 2)
) + (
    S[M // 2] // 2 if M % 2 == 0 else
    0
)

print(ans)
