n = int(input())
p = list(map(int, input().split()))


ans = sum(
    p[i - 1] < p[i] < p[i + 1] or p[i - 1] > p[i] > p[i + 1]
    for i in range(1, n - 1)
)

print(ans)
