from functools import reduce

# 入力
N = int(input())
gA, sA, bA = map(int, input().split())
gB, sB, bB = map(int, input().split())

A = (gA, sA, bA)
B = (gB, sB, bB)


# 各貴金属について、買う／売る可能性のある取引所は一意に定まることを用いて
# 全探索により解を求める
def f(n, r):
    R = len(r)
    return (
        n if R == 0 else
        n + (r[-1][1] - r[-1][0]) * (n // r[-1][0]) if R == 1 else
        reduce(
            max,
            (
                n + (r[0][1] - r[0][0]) * x +
                (r[-1][1] - r[-1][0]) * ((n - r[0][0] * x) // r[-1][0])
                for x in range(n // r[0][0] + 1)
            ),
            n
        ) if R == 2 else
        reduce(
            max,
            (
                n + (r[0][1] - r[0][0]) * x + (r[1][1] - r[1][0]) * y +
                (r[-1][1] - r[-1][0]) *
                ((n - r[0][0] * x - r[1][0] * y) // r[-1][0])
                for x in range(n // r[0][0] + 1)
                for y in range((n - r[0][0] * x) // r[1][0] + 1)
            ),
            n
        )
    )


ans = f(
    f(
        N,
        [
            (a, b)
            for a, b in zip(A, B)
            if a < b
        ]
    ),
    [
        (b, a)
        for b, a in zip(B, A)
        if a > b
    ]
)

# 出力
print(ans)
