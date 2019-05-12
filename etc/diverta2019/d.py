# 入力
N = int(input())

# sqrt(N) + 1 より大きい N の約数dについて、 d - 1 がお気に入りの数か
# 判定し、お気に入りの数であるものの和を解とする
ans = sum(
    N // d - 1
    for d in range(1, int(N**0.5) + 1)
    if N % d == 0 and N // d > 1 and (N // (N // d - 1)) == (N % (N // d - 1))
)

# 出力
print(ans)
