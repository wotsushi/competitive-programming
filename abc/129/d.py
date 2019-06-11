from itertools import takewhile

# 入力
H, W = map(int, input().split())
S = [input() for _ in range(H)]

# 各マスについて、横方向に照らすマスの数と縦方向に照らすマスの数を求める
x = [[0 for _ in range(W)] for _ in range(H)]
y = [[0 for _ in range(W)] for _ in range(H)]

for i, j in ((i, j) for i in range(H) for j in range(W) if S[i][j] == '.'):
    if x[i][j] == 0:
        w = len(list(takewhile(lambda k: S[i][k] == '.', range(j, W))))
        for k in range(j, j + w):
            x[i][k] = w
    if y[i][j] == 0:
        h = len(list(takewhile(lambda k: S[k][j] == '.', range(i, H))))
        for l in range(i, i + h):
            y[l][j] = h

ans = max(
    x[i][j] + y[i][j] - 1
    for i in range(H)
    for j in range(W)
)
# 出力
print(ans)
