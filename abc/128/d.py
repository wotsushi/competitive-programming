# 入力
N, K = map(int, input().split())
V = list(map(int, input().split()))

# 操作Aをa回、操作Bをb回、操作Cをc回実行したときの宝石の価値の合計値U(a, b, c)を求める。
# 各 a, b, c について U(a, b, c) の最大値を解とする。
ans = max(
    sum(sorted(V[:a] + V[(N - b):])[c:])
    for a in range(min(N, K) + 1)
    for b in range(min(N, K) - a + 1)
    for c in range(min(K - a - b, a + b) + 1)
)

# 出力
print(ans)
