from collections import deque
from math import ceil

H, W, K = map(int, input().split())
A = [input() for _ in range(H)]

# 2回目以降の移動において、すべての部屋は開いていると考えてよい
si, sj = next(
    (i, j)
    for i in range(H)
    for j in range(W)
    if A[i][j] == 'S'
)
q = deque()
q.append((si, sj, 0))
T = {(si, sj)}
while q:
    i, j, d = q.popleft()
    if d < K:
        for x, y in (
                (u, v)
                for u, v in ((i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1))
                if 0 <= u < H and 0 <= v < W and
                A[u][v] == '.' and (u, v) not in T
        ):
            q.append((x, y, d + 1))
            T.add((x, y))
ans = 1 + ceil(
    min(
        min(i, j, H - 1 - i, W - 1 - j)
        for i, j in T
    ) / K
)

print(ans)
