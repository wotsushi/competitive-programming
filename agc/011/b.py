from itertools import accumulate

N = int(input())
A = list(map(int, input().split()))

# Aを昇順ソートした列をBとして、
# B_{k + 1} > 2(B_1 + ... + B_k) を満たす最大のkを求める。
# N - k が解となる
B = sorted(A)
S = list(accumulate([0] + B))
ans = N - next(
    i
    for i in reversed(range(N))
    if B[i] > 2 * S[i]
)

print(ans)
