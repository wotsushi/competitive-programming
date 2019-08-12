from fractions import gcd

A, B = map(int, input().split())

xs = []


# 枝刈りしつつ全探索により解を求める
def f(i):
    if i > B:
        return 1
    res = f(i + 1)
    if all(gcd(x, i) == 1 for x in xs):
        xs.append(i)
        res += f(i + 1)
        xs.pop()
    return res


ans = f(A)

print(ans)
