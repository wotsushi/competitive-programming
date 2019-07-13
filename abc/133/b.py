N, D = map(int, input().split())

X = [list(map(int, input().split())) for _ in range(N)]
S = {i**2 for i in range(1000)}
ans = sum(
    a != b and sum((x - y)**2 for x, y in zip(a, b)) in S
    for a in X
    for b in X
) // 2

print(ans)
