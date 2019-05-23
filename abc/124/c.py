# 入力
S = input()

# 白黒白黒... に塗り替える場合と　黒白黒白... に塗り替える場合の塗り替え枚数を比較し解を求める
ans = min(
    sum(S[i] == str(i % 2) for i in range(len(S))),
    sum(S[i] == str((i + 1) % 2) for i in range(len(S)))
)

# 出力
print(ans)
