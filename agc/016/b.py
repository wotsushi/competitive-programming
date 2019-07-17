N = int(input())
a = list(map(int, input().split()))

# Yesならば aの任意の2要素の差は高々1である
# 小さい方の値を発言している猫はそれぞれ異なる帽子を被る必要がある
# 大きい方の値を発言している猫は同じ帽子を被る猫が少なくとも他に一匹存在する必要がある
L = min(a)
R = max(a)
ans = (
    'Yes' if R - L == 0 and (N >= 2 * L or N == L + 1) or
    R - L == 1 and 2 * (L + 1) - N <= sum(x == L for x in a) <= L else
    'No'
)

print(ans)
