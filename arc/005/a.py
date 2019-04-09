# 入力
N = int(input())
w = input()[:-1].split()

# 出力
ans = [x.lower() for x in w].count('takahashikun')
print(ans)
