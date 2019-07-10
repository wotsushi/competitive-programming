L, R = map(int, input().split())

ans = min(
    (i * j) % 2019
    for i in range(L, min(R, L + 2019) + 1)
    for j in range(i + 1, min(R, i + 2019) + 1)
)

print(ans)
