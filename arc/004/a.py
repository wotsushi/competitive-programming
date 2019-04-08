from itertools import combinations

# 入力
N = int(input())
x, y = zip(*(map(int, input().split()) for _ in range(N)))

# 全探索により解を求める
ans = max(
    ((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)**0.5
    for p1, p2 in combinations(zip(x, y), 2)
)

# 出力
print(ans)
