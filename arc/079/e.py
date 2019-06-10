# 入力
N = int(input())
a = list(map(int, input().split()))

# 最大要素に対して、まとめて操作を実行するのを繰り返す
b = [x for x in a]
c = 0
while max(b) >= N:
    i = max(range(N), key=lambda i: b[i])
    c += b[i] // N
    for j in range(N):
        if j != i:
            b[j] += b[i] // N
    b[i] %= N

ans = c

# 出力
print(ans)
