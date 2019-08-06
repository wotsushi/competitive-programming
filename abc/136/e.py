from itertools import accumulate

N, K = map(int, input().split())
A = list(map(int, input().split()))


# Aの要素をK回以下の操作ですべてdの倍数にできるならば真を返す関数
def f(d):
    B = sorted(a % d for a in A)
    C = [d - b for b in B]
    X = list(accumulate(B))
    Y = list(accumulate(C))
    return any(
        X[j] == (Y[-1] - Y[j]) <= K
        for j in range(N)
    )


# 解の候補はsum(A)の約数である
S = sum(A)
ans = max(
    (
        S // d if f(S // d) else
        d if f(d) else
        0
    )
    for d in range(1, int(S**0.5) + 2)
    if S % d == 0
)

print(ans)
