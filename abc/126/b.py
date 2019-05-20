# 入力
S = input()

a = int(S[:2])
b = int(S[2:])

ans = (
    'YYMM' if not 1 <= a <= 12 and 1 <= b <= 12 else
    'MMYY' if 1 <= a <= 12 and not 1 <= b <= 12 else
    'AMBIGUOUS' if 1 <= a <= 12 and 1 <= b <= 12 else
    'NA'
)

# 出力
print(ans)
