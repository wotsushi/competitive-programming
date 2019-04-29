from fractions import gcd
from itertools import accumulate

# 入力
N = int(input())
A = list(map(int, input().split()))

# 先頭から連続する要素の最大公約数の列
L = [0] + list(accumulate(A, gcd))
# 末尾から連続する要素の最大公約数の列
R = [0] + list(accumulate(reversed(A), gcd))

# Aの各要素について、それを使用しない場合の最大公約数の最大値をL, Rを用いて求める
ans = max(
    gcd(L[k], R[-(k + 2)])
    for k in range(N)
)

# 出力
print(ans)
