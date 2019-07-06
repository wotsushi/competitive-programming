N = int(input())
A, B = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

# 貪欲に大きい値を選べばよい
ans = sum(map(max, zip(A, B)))

print(ans)
