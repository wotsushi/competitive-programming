# 入力
N = int(input())
s = [input() for _ in range(N)]

# 先頭がBである／ではない、末尾がAである／ではない文字列の個数を数え上げる
a = sum(t[0] != 'B' and t[-1] == 'A' for t in s)
b = sum(t[0] == 'B' and t[-1] != 'A' for t in s)
ba = sum(t[0] == 'B' and t[-1] == 'A' for t in s)

# 最初に、先頭文字がBではない、かつ、末尾文字がAの文字列を先頭におく（そのような文字列が存在すれば）
# 次に、先頭文字がB、かつ、末尾文字がAの文字列を可能な限り連結する
# 次に、（先頭文字がB、かつ、末尾文字がAでない文字列）と（先頭文字がBではない、かつ、末尾文字がAの文字列）を交互に連結する
# 最後に、余っている文字列を適当に連結する
ans = (
    sum(t.count('AB') for t in s) +
    (
        ba if a > 0 else
        max(0, ba - 1)
    ) +
    (
        min(1, b) if a == 0 and ba > 0 else
        min(a, b)
    )
)

# 出力
print(ans)
