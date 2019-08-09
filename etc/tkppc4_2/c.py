A, B = map(int, input().split())

ans = (
    'Angel' if B % 4 == 1 or B % 4 == 2 or B % 4 == 3 and A % 2 == 1 else
    'Devil'
)

print(ans)
