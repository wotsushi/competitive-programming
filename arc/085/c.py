# 入力
N, M = map(int, input().split())

# (等比*等差)数列の和の公式を用いる
ans = (100 * N + 1800 * M) * 2**M

# 出力
print(ans)
