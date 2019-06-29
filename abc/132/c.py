N = int(input())
d = list(map(int, input().split()))

# ソートして中央値付近の差をみればよい
D = sorted(d)
ans = D[N // 2] - D[N // 2 - 1]

print(ans)
