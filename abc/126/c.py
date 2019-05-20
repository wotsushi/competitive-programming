from math import ceil

# 入力
N, K = map(int, input().split())

# サイコロの各目について勝率を求め、それらの和を解とする
ans = sum(
    1 / (2**((ceil(K / i) - 1).bit_length()))
    for i in range(1, N + 1)
) / N

# 出力
print(ans)
