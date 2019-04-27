from functools import reduce

# 入力
s = input()
x, y = map(int, input().split())

C = [len(fs) for fs in s.split('T')]


# 動的計画法により、各軸について到達可能な座標の集合を求め、目標の座標に到達可能か判定
def f(cs, t):
    return t in reduce(
        lambda acc, c: {i + c for i in acc} | {i - c for i in acc},
        cs,
        {0}
    )


ans = (
    'Yes' if f(C[2::2], x - C[0]) and f(C[1::2], y) else
    'No'
)
# 出力
print(ans)
