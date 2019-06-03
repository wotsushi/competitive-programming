# 入力
s = input()
K = int(input())

# 先頭文字から順に可能な限りaにする
# 余った操作回数はすべて末尾文字に適用する
t = list(s)
L = K
for i in range(len(s)):
    d = 123 - ord(s[i])
    if 1 <= d <= min(25, L):
        t[i] = 'a'
        L -= d
t[-1] = chr((ord(t[-1]) - 97 + L) % 26 + 97)
ans = ''.join(t)

# 出力
print(ans)
