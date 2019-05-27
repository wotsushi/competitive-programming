# 入力
N = int(input())
s = list(map(int, input().split()))

M = N - 1
opt = 0
# 各 A, B について解候補を全探索する
for d in range(1, M // 2 + 1):
    U = {0, M}
    q = M // d
    r = M % d
    acc = 0
    for i in range(1, M // d):
        x = i * d
        y = (q - i) * d + r
        if x == y or x in U or y in U:
            break
        U.add(x)
        U.add(y)
        acc += s[x] + s[y]
        opt = max(opt, acc)

ans = opt
# 出力
print(ans)
