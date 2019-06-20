from itertools import accumulate

# 入力
N, K = map(int, input().split())
a = list(map(int, input().split()))

# 各iについて、 累積和を用いて a_i + ... a_j >= K を満たす
# 最小のjを求め、 (N + 1 - j) の和を解とする
acc = [0] + list(accumulate(a)) + [K]


def bis(p, ok, ng):
    mid = (ok + ng) // 2
    return (
        ok if abs(ok - ng) == 1 else
        bis(p, mid, ng) if p(mid) else
        bis(p, ok, mid)
    )


ans = sum(
    N + 1 - bis(
        lambda j: acc[j] - acc[i - 1] >= K,
        N + 1,
        i - 1
    )
    for i in range(1, N + 1)
)

# 出力
print(ans)
