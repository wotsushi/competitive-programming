A, B = map(int, input().split())

# A + B が偶数ならば A + B / 2, そうでなければ不可
ans = (
    (A + B) // 2 if (A + B) % 2 == 0 else
    'IMPOSSIBLE'
)

print(ans)
