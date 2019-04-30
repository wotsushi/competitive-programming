from heapq import heappush, heappop


# 入力
N = int(input())
x, y = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

# x座標およびy座標について街をソートし、ソート後に隣り合う街を辺で結んだ重み付きグラフを作成する
# 作成したグラフに対してプリム法により解を求める
ts = list(zip(range(1, N + 1), x, y))
ts_x = sorted(ts, key=lambda t: t[1])
ts_y = sorted(ts, key=lambda t: t[2])
G = [{} for _ in range(N + 1)]
for ((i, a, b), (j, c, d)) in zip(ts_x[1:], ts_x):
    G[i][j] = min(abs(c - a), abs(d - b))
    G[j][i] = G[i][j]
for ((i, a, b), (j, c, d)) in zip(ts_y[1:], ts_y):
    G[i][j] = min(abs(c - a), abs(d - b))
    G[j][i] = G[i][j]


def prim(G):
    used = [False for _ in range(len(G))]
    res = 0
    q = []
    used[1] = True
    for j, w in G[1].items():
        heappush(q, (w, j))
    while q:
        w, j = heappop(q)
        if not used[j]:
            used[j] = True
            res += w
            for j2, w2 in G[j].items():
                heappush(q, (w2, j2))
    return res


ans = prim(G)
# 出力
print(ans)
