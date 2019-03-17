from string import ascii_lowercase
from functools import reduce
from operator import mul

# 入力
N = int(input())
S = input()

# 解は(各アルファベットの出現回数+1)の総積
ans = (
    reduce(
        mul,
        map(
            lambda c: S.count(c) + 1,
            ascii_lowercase
        )
    ) - 1
) % (10**9 + 7)

# 出力
print(ans)
