N, M = map(int, input().split())
X = list(map(int, input().split()))

# ソートして、差が大きい区間をサボるようにコマを配置すればよい
Y = sorted(X)
ans = sum(
    sorted(
        (
            a - b
            for a, b in zip(Y[1:], Y)
        ),
        reverse=True
    )[(N - 1):]
)

print(ans)
