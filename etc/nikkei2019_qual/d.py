from collections import deque

# 入力
N, M = map(int, input().split())
A, B = zip(*(map(int, input().split()) for _ in range(N - 1 + M)))

# 各頂点の深さを求め、深さを利用して元の木を復元する
G = [set() for _ in range(N + 1)]
G_inv = [set() for _ in range(N + 1)]
for a, b in zip(A, B):
    G[a].add(b)
    G_inv[b].add(a)
deg = [len(G_inv[i]) for i in range(N + 1)]
V = [i for i in range(1, N + 1) if not G_inv[i]]
deq = deque(V)
while deq:
    i = deq.popleft()
    for j in G[i]:
        deg[j] -= 1
        if deg[j] == 0:
            deq.append(j)
            V.append(j)

R = {i: r for r, i in enumerate(V)}
ans = '\n'.join(
    str(max(G_inv[i], key=lambda j: R[j], default=0))
    for i in range(1, N + 1)
)

# 出力
print(ans)
