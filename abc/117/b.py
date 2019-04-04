# 入力
N = int(input())
L = list(map(int, input().split()))

# 出力
ans = 'Yes' if 2 * max(L) < sum(L) else 'No'
print(ans)
