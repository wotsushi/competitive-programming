# 入力
N = int(input())
A, B = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

ans = '\n'.join(
    '-1' if a == b else
    str(abs(a - b))
    for a, b in zip(A, B)
)

# 出力
print(ans)
