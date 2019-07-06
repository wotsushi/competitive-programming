S = input()

T = sorted(S)
ans = (
    'Yes' if T[0] == T[1] and T[1] != T[2] and T[2] == T[3] else
    'No'
)

print(ans)
