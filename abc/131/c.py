from fractions import gcd

# 入力
A, B, C, D = map(int, input().split())


# CまたはDで割り切れる数を求め、それを差し引いて求める
def f(x):
    return x - (x // C + x // D - x // (C * D // gcd(C, D)))


ans = f(B) - f(A - 1)

# 出力
print(ans)
