from functools import lru_cache
from itertools import product

# 入力
N = int(input())

# 3文字のACGT文字列のリスト
T = [''.join(t) for t in product(('A', 'C', 'G', 'T'), repeat=3)]


# ACGT文字列が問題の条件にマッチするならば真となる述語
@lru_cache(maxsize=None)
def p(s):
    return all(
        'AGC' not in s[:i] + s[i + 1:i + 2] + s[i] + s[i + 2:]
        for i in range(len(s))
    )


# 長さがi、かつ、末尾3文字がs、かつ、問題の条件にマッチする文字列の個数を返す
@lru_cache(maxsize=None)
def f(i, s):
    return (
        0 if i == 3 and not p(s) else
        1 if i == 3 and p(s) else
        sum(f(i - 1, t) for t in T if t[1:] == s[:2] and p(t + s[-1]))
    )


# 解は、すべての長さ3のACGT文字列tに対して、f(N, t) の和である。
ans = sum(f(N, t) for t in T) % (10**9 + 7)

# 出力
print(ans)
