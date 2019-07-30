N = int(input())
p = list(map(int, input().split()))

ans = (
    'YES' if sum(i != q for i, q in enumerate(p, 1)) <= 2 else
    'NO'
)

print(ans)
