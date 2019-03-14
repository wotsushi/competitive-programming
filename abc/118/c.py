from fractions import gcd
from functools import reduce

# 入力
N = int(input())
A = map(int, input().split())

# 解はAの最大公約数
ans = reduce(gcd, A)

# 出力
print(ans)
