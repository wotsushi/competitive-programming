from collections import Counter

N, P, Q = map(int, input().split())
A = list(map(int, input().split()))

# x = (P + Q) / 2, y + z = (P - Q) / 2
# が成り立つことを利用する
c = Counter()
t = 0
s = 0
for a in reversed(A):
    if 2 * a == P + Q:
        s += t
    t += c[(P - Q) // 2 - a]
    c[a] += 1
ans = (
    s if (P + Q) % 2 == 0 else
    0
)

print(ans)
