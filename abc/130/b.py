from itertools import accumulate

# 入力
N, X = map(int, input().split())
L = list(map(int, input().split()))

ans = 1 + sum(acc <= X for acc in accumulate(L))

# 出力
print(ans)
