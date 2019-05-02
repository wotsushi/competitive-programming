from heapq import heappush, heappop

# 入力
N = int(input())
A = list(map(int, input().split()))

# 先頭からi(N <=i <= 2N)番目までの要素からN個の要素を選んだときの和の最大値を求める
ql = []
for a in A[:N]:
    heappush(ql, a)
L = [sum(A[:N])]
for a in A[N:(2 * N)]:
    heappush(ql, a)
    m = heappop(ql)
    L.append(L[-1] + a - m)

# 末尾からi(N <=i <= 2N)番目までの要素からN個の要素を選んだときの和の最小値を求める
qr = []
for a in A[-N:]:
    heappush(qr, -a)
R = [sum(A[-N:])]
for a in A[-(N + 1):-(2 * N + 1):-1]:
    heappush(qr, -a)
    m = -heappop(qr)
    R.append(R[-1] + a - m)

# L, R を用いて解を求める
ans = max(l - r for l, r in zip(L, R[::-1]))

# 出力
print(ans)
