N, M = map(int, input().split())
A, B = (
    zip(*(map(int, input().split()) for _ in range(M))) if M else
    ((), ())
)

# グラフが二部グラフならば二集合間に辺を張れる
# そうでなければ完全グラフになるように辺を張れる
G = [set() for _ in range(N + 1)]
for x, y in zip(A, B):
    G[x].add(y)
    G[y].add(x)
dp = [0 for _ in range(N + 1)]
q = []
q.append(1)
dp[1] = 1
is_bi = True
while q:
    i = q.pop()
    for j in G[i]:
        if dp[j] == 0:
            dp[j] = -dp[i]
            q.append(j)
        else:
            is_bi &= dp[j] == -dp[i]
ans = (
    sum(x == 1 for x in dp) * sum(x == -1 for x in dp) - M if is_bi else
    N * (N - 1) // 2 - M
)

print(ans)
