# 入力
S = input()

# 適当に取り除く操作を繰り返せばよい
ans = 2 * min(S.count('0'), S.count('1'))

# 出力
print(ans)
