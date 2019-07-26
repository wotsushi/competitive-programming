N = int(input())
A = [int(input()) for _ in range(N)]

# 最大値をとるインデックスを求めておく
k = max(range(N), key=lambda i: A[i])
ans = '\n'.join(
    str(
        max(A[:k] + A[k + 1:]) if i == k else
        A[k]
    )
    for i in range(N)
)

print(ans)
