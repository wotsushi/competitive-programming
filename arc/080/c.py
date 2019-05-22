# 入力
N = int(input())
a = list(map(int, input().split()))

# 各整数を素因数分解したとき、因数2の個数に着目して判定する
X = sum(x % 2 == 1 for x in a)
Y = sum(x % 2 == 0 and x % 4 == 2 for x in a)
Z = sum(x % 4 == 0 for x in a)
ans = (
    'Yes' if X <= Z or X == Z + 1 and Y == 0 else
    'No'
)

# 出力
print(ans)
