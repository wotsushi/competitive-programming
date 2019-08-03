N, M = map(int, input().split())
a, b = zip(*(map(int, input().split()) for _ in range(M)))


G = [set() for _ in range(N + 1)]
for x, y in zip(a, b):
    G[x].add(y)
    G[y].add(x)


# 次数4の頂点間のパスの数が4でないならばTrueを返す
def f():
    x, y = (i for i in range(1, N + 1) if len(G[i]) == 4)
    q = []
    dp = [0 for _ in range(N + 1)]
    q.append(x)
    dp[x] = 1
    while q:
        i = q.pop()
        for j in G[i]:
            if j != y and dp[j] == 0:
                q.append(j)
            dp[j] += 1
    return dp[y] != 4


# 以下のいずれかを満たすならば、かつ、そのときに限りYes
# - 次数4の頂点間を結ぶ異なる4つのパスが存在しない場合
# - 各頂点の次数は2または4であり、次数4の頂点は3個存在する場合
# - 各頂点の次数は偶数であり、次数が6以上の頂点が存在する場合
ans = (
    'Yes' if (
        all(len(G[i]) % 2 == 0 for i in range(1, N + 1)) and
        (
            any(len(G[i]) >= 6 for i in range(1, N + 1)) or
            sum(len(G[i]) == 4 for i in range(1, N + 1)) >= 3 or
            sum(len(G[i]) == 4 for i in range(1, N + 1)) == 2 and f()
        )
    ) else
    'No'
)

print(ans)
