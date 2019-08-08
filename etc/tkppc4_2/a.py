x, y = map(int, input().split())

# 移動可能ならばyは非負の偶数であり、移動回数は必ずy/2である
ans = (
    y // 2 if (
        y % 2 == 0 and
        y >= 0 and
        abs(x) <= y // 2 and
        (x - y // 2) % 2 == 0
    ) else
    -1
)

print(ans)
