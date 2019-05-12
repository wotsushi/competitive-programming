# 入力
R, G, B, N = map(int, input().split())

# とりうるすべてのr, gの組に関して、条件を満たすbが存在するかを数え上げる
ans = sum(
    N - r * R - g * G >= 0 and (N - r * R - g * G) % B == 0
    for r in range(N // R + 1)
    for g in range((N - r * R) // G + 1)
)

# 出力
print(ans)
