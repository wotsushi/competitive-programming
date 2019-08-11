H, W = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(H)]

# 左上からコインの枚数が奇数であるマスのコインを右または下に移す
b = [[t for t in x] for x in a]
moves = []
for i in range(1, H + 1):
    for j in range(1, W + 1):
        if b[i - 1][j - 1] % 2 == 1:
            if j < W:
                b[i - 1][j] += 1
                moves.append((i, j, i, j + 1))
            elif i < H:
                b[i][j - 1] += 1
                moves.append((i, j, i + 1, j))
ans = (
    '{}\n{}'.format(
        len(moves),
        '\n'.join(
            ' '.join([str(y1), str(x1), str(y2), str(x2)])
            for (y1, x1, y2, x2) in moves
        )
    ) if moves else
    '0'
)

print(ans)
