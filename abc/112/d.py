N, M = map(int, input().split())

# Mの約数dのうち、 dN <= M を満たす最大のdが解
ans = max(
    (
        M // d if (M // d) * N <= M else
        d if d * N <= M else
        1
    )
    for d in range(1, int(M**0.5) + 10)
    if M % d == 0
)

print(ans)
