from collections import Counter

N = int(input())
a = list(map(int, input().split()))

c = Counter(a)
x = sorted(c.keys())

# aに4種類以上異なる値が存在する場合、No
ans = (
    'Yes' if (
        len(x) == 3 and x[0] ^ x[1] == x[2] and
        c[x[0]] == c[x[1]] == c[x[2]] or
        len(x) == 2 and x[0] == 0 and c[x[1]] == 2 * c[0] or
        len(x) == 1 and x[0] == 0
    ) else
    'No'
)

print(ans)
