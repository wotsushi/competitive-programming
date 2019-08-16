N = int(input())
A = list(map(int, input().split()))

# X xor Y = X + Y ならば X & Y = 0 が成り立つことを利用して
# しゃくとり法により解を求める
j = 0
acc = 0
s = 0
for i, a in enumerate(A):
    while a & acc != 0 and j < i:
        acc ^= A[j]
        j += 1
    s += i - j + 1
    acc ^= a
ans = s

print(ans)
