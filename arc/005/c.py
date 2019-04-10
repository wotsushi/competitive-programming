from heapq import heappush, heappop

# 入力
H, W = map(int, input().split())
c = [input() for _ in range(H)]

# 各区画に到達するまでに塀を超える最小回数
dp = dict()
# ダイクストラ法で用いる優先度付きキュー
q = []
heappush(
    q,
    next((0, i, j) for i in range(H) for j in range(W) if c[i][j] == 's')
)
# ダイクストラ法によりdpを求める
while q:
    k, i, j = heappop(q)
    if (i, j) in dp:
        continue
    dp[(i, j)] = k
    for y, x in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
        if 0 <= y < H and 0 <= x < W and (y, x) not in dp:
            heappush(
                q,
                (
                    k + 1 if c[y][x] == '#' else k,
                    y,
                    x
                )
            )
# 出力
ans = 'YES' if dp[
    next((i, j) for i in range(H) for j in range(W) if c[i][j] == 'g')
] <= 2 else 'NO'
print(ans)
