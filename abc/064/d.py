from functools import reduce

# 入力
N = int(input())
S = input()

# 閉じられていない '(' の個数だけ S の末尾に ')' を、
# 閉じられていない ')' の個数だけ S の先頭に '(' を付与した文字列が解である
a, b = reduce(
    lambda acc, s:
        (
            (
                acc[0] + 1 if s == '(' else
                max(0, acc[0] - 1)
            ),
            (
                acc[1] + 1 if s == ')' and acc[0] == 0 else
                acc[1]
            )
        ),
    S,
    (0, 0)
)
ans = b * '(' + S + a * ')'

# 出力
print(ans)
