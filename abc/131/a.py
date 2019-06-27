# 入力
S = input()

ans = (
    'Bad' if S[0] == S[1] or S[1] == S[2] or S[2] == S[3] else
    'Good'
)

# 出力
print(ans)
