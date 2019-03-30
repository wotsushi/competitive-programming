# 入力
K, A, B = map(int, input().split())

# 貪欲的にビスケットの枚数を最大化する
n = max(0, (K - A + 1))
ans = (
     min(K, A) + (B - A) * (n // 2) + n % 2 if B >= A + 3 else
     K + 1
)

# 出力
print(ans)
