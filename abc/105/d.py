from itertools import accumulate
from collections import Counter

N, M = map(int, input().split())
A = list(map(int, input().split()))

# 累積和とCounterを用いて各lについて、A_l + ... + A_r が M の倍数となるような
# rの個数をO(1)で求める
R = list(accumulate([0] + A, lambda acc, a: (acc + a) % M))
C = Counter(R)
s = 0
for i in range(N):
    C[R[i]] -= 1
    s += C[R[i]]
ans = s

print(ans)
