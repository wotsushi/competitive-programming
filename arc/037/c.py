from bisect import bisect

N, K = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))


def bis(p, ok, ng):
    mid = (ok + ng) // 2
    return (
        ok if abs(ok - ng) == 1 else
        bis(p, mid, ng) if p(mid) else
        bis(p, ok, mid)
    )


# 二分探索により、x以下の整数がK個以上となるような最小のxを求める
c = sorted(b)
ans = bis(
    lambda x: sum(bisect(c, x // y) for y in a) >= K,
    10**20,
    0
)

print(ans)
