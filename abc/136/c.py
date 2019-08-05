from functools import reduce

N = int(input())
H = list(map(int, input().split()))

# 先頭から順に、可能な限りマスの高さを低くする戦略により、単調非減少にできるか判定
ans, _ = reduce(
    lambda acc, h: (
        (
            'Yes' if acc[0] == 'Yes' and acc[1] <= h else
            'No'
        ),
        h if acc[1] >= h else
        h - 1
    ),
    H,
    ('Yes', 0)
)

print(ans)
