N, K = map(int, input().split())
h = [int(input()) for _ in range(N)]

x = sorted(h)
ans = min(b - a for a, b in zip(x, x[(K - 1):]))

print(ans)
