# 入力
N, M = map(int, input().split())
L, R = (
    zip(*(map(int, input().split()) for _ in range(M))) if M else
    ((), ())
)

ans = max(min(R) - max(L) + 1, 0)

# 出力
print(ans)
