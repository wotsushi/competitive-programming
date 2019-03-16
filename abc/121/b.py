# 入力
N, M, C = map(int, input().split())
B = list(map(int, input().split()))
A = [list(map(int, input().split())) for _ in range(N)]

# 出力
ans = sum(1 for a in A if sum(x * y for x, y in zip(a, B)) + C > 0)
print(ans)
