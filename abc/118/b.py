# 入力
N, M = map(int, input().split())
K, A = zip(*(
    (int(t[0]), list(map(int, t[1].split())))
    for t in (input().split(maxsplit=1) for _ in range(N))
))

# 素直にカウント
ans = sum(
    all(k in a for a in A)
    for k in range(1, M + 1)
)

# 出力
print(ans)
