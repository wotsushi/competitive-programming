# 入力
N = int(input())
d = [int(input()) for _ in range(N)]

# (dの最大値) <= (他のdの和)ならば解は0
# そうでなければ(dの最大値)-(他のdの和)が解
ans = '{}\n{}'.format(
    str(sum(d)),
    str(max(2 * max(d) - sum(d), 0))
)

# 出力
print(ans)
