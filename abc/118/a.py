# 入力
A, B = map(int, input().split())

# 素直に解を求める
ans = A + B if B % A == 0 else B - A

# 出力
print(ans)
