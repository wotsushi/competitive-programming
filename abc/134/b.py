from math import ceil

N, D = map(int, input().split())

ans = ceil(N / (2 * D + 1))

print(ans)
