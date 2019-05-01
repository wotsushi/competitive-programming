# 入力
N = int(input())
A = list(map(int, input().split()))

C = [abs(a) for a in A]
# 負である要素の数が偶数ならば、すべて非負にできる
# そうでなければ、絶対値が最小の要素を除いたすべての要素を非負にする
ans = (
    sum(C) if sum(a < 0 for a in A) % 2 == 0 else
    sum(C) - 2 * min(C)
)

# 出力
print(ans)
