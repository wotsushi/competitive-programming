A, B = map(int, input().split())

ans = (
    B if A >= 13 else
    B // 2 if A >= 6 else
    0
)

print(ans)
