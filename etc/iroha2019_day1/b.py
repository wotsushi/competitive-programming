S = input()
K = int(input())

i = K % len(S)
ans = S[i:] + S[:i]

print(ans)
