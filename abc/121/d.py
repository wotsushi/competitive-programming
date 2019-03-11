# 入力
A, B = map(int, input().split())


# f(0, a)を返す
def g(a):
    m = a % 4
    return (
        a if m == 0 else
        1 if m == 1 else
        a + 1 if m == 2 else
        0
    )


# b >= a >= 1 ならば f(a, b) = f(0, b) ^ f(0, a - 1) を用いる
ans = g(B) ^ g(A - 1) if A > 0 else g(B)

# 出力
print(ans)
