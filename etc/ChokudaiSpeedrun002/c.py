N = int(input())
A, B = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

ans = max(
    a + b
    for a, b in zip(A, B)
)

print(ans)
