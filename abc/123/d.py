from heapq import heappush, heappop

# 入力
X, Y, Z, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

INF = 10**15

# 幅優先探索により解を求める
a = sorted(A, reverse=True) + [-INF]
b = sorted(B, reverse=True) + [-INF]
c = sorted(C, reverse=True) + [-INF]
q = []
heappush(q, (-(a[0] + b[0] + c[0]), 0, 0, 0))
m = 0
d = []
u = set()
while m < K:
    s, i, j, k = heappop(q)
    if (i, j, k) not in u:
        d.append(-s)
        u.add((i, j, k))
        heappush(q, (-(a[i + 1] + b[j] + c[k]), i + 1, j, k))
        heappush(q, (-(a[i] + b[j + 1] + c[k]), i, j + 1, k))
        heappush(q, (-(a[i] + b[j] + c[k + 1]), i, j, k + 1))
        m += 1
ans = '\n'.join(map(str, d))

# 出力
print(ans)
