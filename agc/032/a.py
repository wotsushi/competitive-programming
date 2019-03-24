# 入力
N = int(input())
b = list(map(int, input().split()))


# 逆順から操作手順を求める
def f(c):
    j = max([j for j, x in enumerate(c, 1) if j == x], default=0)
    return (
        f(c[:(j-1)] + c[j:]) + [j] if j and len(c) >= 2 else
        [j] if j and len(c) == 1 else
        []
    )


res = f(b)

# 出力
ans = '\n'.join(map(str, res)) if len(res) == N else -1
print(ans)
