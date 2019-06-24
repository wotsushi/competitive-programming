# 入力
N, K, Q = map(int, input().split())
A = list(map(int, input().split()))

INF = 10**20

# Y = A_1, .., A_N のときの X - Y の最小値を求める
# Y を決め打つと、 X - Y の最小値はO(NlogN)で求められる


def f(b):
    i = 0
    T = []
    while i < N:
        S = []
        while i < N and A[i] >= b:
            S.append(A[i])
            i += 1
        if len(S) >= K:
            T.extend(sorted(S)[:(len(S) - K + 1)])
        i += 1
    return (
        sorted(T)[Q - 1] if len(T) >= Q else
        INF
    )


ans = min(f(a) - a for a in A)

# 出力
print(ans)
