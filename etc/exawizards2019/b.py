# 入力
N = int(input())
s = input()

# 出力
ans = 'Yes' if s.count('R') > s.count('B') else 'No'
print(ans)
