from collections import Counter
from string import ascii_lowercase

A = input()


# 英小文字xについて、Aに含まれるxの個数をc[x]で表す。
# 解は、1 + c['a'](c['b'] + ... + c['z']) +
# c['b'](c['c'] + ... + c['z']) + c['y']['z'] である。
c = Counter(A)
ans = 1 + sum(
    c[x] * sum(c[y] for y in ascii_lowercase if x < y)
    for x in ascii_lowercase
)

print(ans)
