N, K = map(int, input().split())

# K = 1 がエッジケースであることに注意
ans = (
    0 if K == 1 else
    N - K
)

print(ans)
