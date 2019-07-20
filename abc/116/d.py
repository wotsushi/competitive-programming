from heapq import heappush, heappop

N, K = map(int, input().split())
t, d = (
    zip(*(map(int, input().split()) for _ in range(N))) if N else
    ((), ())
)

# おいしさについて貪欲に寿司を食べたときの満足ポイントを求める
# その後、種類ボーナスを1個ずつ増やしたときの満足ポイントをそれぞれ求め、
# それらの最大値を求める
S = sorted(zip(d, t), reverse=True)
q = []
v = set()
s = 0
for D, T in S[:K]:
    s += D
    if T in v:
        heappush(q, D)
    else:
        v.add(T)
s += len(v)**2
opt = s
for D, T in S[K:]:
    if T not in v and q:
        z = heappop(q)
        s += D + 2 * len(v) + 1 - z
        v.add(T)
        opt = max(opt, s)
ans = opt

print(ans)
