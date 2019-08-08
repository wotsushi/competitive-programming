N = int(input())

ans = min(9, N) + max(0, min(999, N) - 99) + max(0, min(99999, N) - 9999)

print(ans)
