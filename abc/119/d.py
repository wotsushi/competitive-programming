from bisect import bisect_right
# 入力
A, B, Q = map(int, input().split())
s = [int(input()) for _ in range(A)]
t = [int(input()) for _ in range(B)]
x = [int(input()) for _ in range(Q)]

# 計算の便宜のため番兵を導入
INF = 10 ** 18
S = [-INF] + s + [INF]
T = [-INF] + t + [INF]


# 指定した変位に対する問に二分探索を用いて回答
def f(y):
    i = bisect_right(S, y)
    j = bisect_right(T, y)
    return min(
        abs(b - a) + min(abs(a - y), abs(b - y))
        for a in (S[i - 1], S[i])
        for b in (T[j - 1], T[j])
    )


# 各問に対して、fにより解を得る
ans = '\n'.join(map(str, map(f, x)))

# 出力
print(ans)
