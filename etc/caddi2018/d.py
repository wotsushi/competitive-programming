# 入力
N = int(input())
a = [int(input()) for _ in range(N)]

# aの要素がすべて奇数ならば、かつ、そのときに限りルンルンが勝つ
ans = (
    'first' if any(x % 2 == 1 for x in a) else
    'second'
)

# 出力
print(ans)
