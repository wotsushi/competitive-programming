# 入力
N, M = map(int, input().split())
x, y = zip(*(map(int, input().split()) for _ in range(M)))

# シミュレーションにより、赤いボールが入っている可能性のある箱を列挙
c = [1 for _ in range(N + 1)]
r = [False for _ in range(N + 1)]
r[1] = True
for a, b in zip(x, y):
    c[b] += 1
    r[b] |= r[a]
    c[a] -= 1
    r[a] &= c[a] >= 1
ans = sum(r)

# 出力
print(ans)
