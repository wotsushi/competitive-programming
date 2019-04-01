from functools import reduce

# 入力
N, Q = map(int, input().split())
s = input()
t, d = zip(*(input().split() for _ in range(Q)))


# めぐる式二分法
def bis(p, ok=-1, ng=10**18):
    mid = (ok + ng) // 2
    return (
        ok if abs(ok - ng) == 1 else
        bis(p, mid, ng) if p(mid) else
        bis(p, ok, mid)
    )


# Q回の呪文詠唱後、マスiにいたゴーレムが移動したマス。ただし、
# 0の場合、マス1から左に移動しようとして消滅したことを、
# N + 1の場合、マスNから右に移動しようとして消滅したことを表す。
def f(i):
    return reduce(
        lambda j, q: (
            0 if j == 0 else
            j - 1 if 1 <= j <= N and s[j - 1] == q[0] and q[1] == 'L' else
            j if 1 <= j <= N and s[j - 1] != q[0] else
            j + 1 if 1 <= j <= N and s[j - 1] == q[0] and q[1] == 'R' else
            N + 1
        ),
        zip(t, d),
        i
    )


# 二分法により、マス1から左に移動しようとして消滅したゴーレムの数と
# マスNから右に移動しようとして消滅したゴーレムの数の和を求める
ans = (
    bis(lambda i: f(i) == N + 1, ok=N + 1, ng=0) -
    bis(lambda i: f(i) == 0, ok=0, ng=N + 1) -
    1
)
print(ans)
