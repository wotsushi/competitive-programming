from math import ceil

# 入力
N, A, B = map(int, input().split())
h = [int(input()) for _ in range(N)]


# 二分法により解を求める
def bis(p, ok, ng):
    mid = (ok + ng) // 2
    return (
        ok if abs(ok - ng) == 1 else
        bis(p, mid, ng) if p(mid) else
        bis(p, ok, mid)
    )


ans = bis(
    lambda k: sum(max(0, ceil((x - k * B) / (A - B))) for x in h) <= k,
    10**10,
    0
)

# 出力
print(ans)
