# 入力
N = int(input())
A = list(map(int, input().split()))

# 正-負をなるべく多く達成するように操作する
P = sorted((a for a in A if a >= 0), reverse=True)
Q = sorted(a for a in A if a < 0)

x, y = [], []
if len(P) == 2 and not Q:
    Y, X = P.pop(), P.pop()
    x.append(X)
    y.append(Y)
    P.append(X - Y)
if len(P) >= 3 and not Q:
    X, Y = P.pop(), P.pop()
    x.append(X)
    y.append(Y)
    Q.append(X - Y)
if not P and len(Q) >= 2:
    X, Y = Q.pop(), Q.pop()
    x.append(X)
    y.append(Y)
    P.append(X - Y)
while len(P) >= 2 and Q:
    X, Y = Q.pop(), P.pop()
    x.append(X)
    y.append(Y)
    Q.append(X - Y)
while Q:
    X, Y = P.pop(), Q.pop()
    x.append(X)
    y.append(Y)
    P.append(X - Y)

ans = (
    '{}\n{}'.format(
        P[0],
        '\n'.join(
            '{} {}'.format(X, Y)
            for X, Y in zip(x, y)
        )
    )
)

# 出力
print(ans)
