# 入力
N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]

# Aに対してワーシャルフロイドを適用した結果と比較して解を求める
ans = (
    -1 if any(
        A[u][v] > A[u][k] + A[k][v]
        for u in range(N)
        for v in range(u + 1, N)
        for k in range(N)
        if k != u and k != v
    ) else
    sum(sum(a) for a in A) // 2 - sum(
        A[u][v]
        for u in range(N)
        for v in range(u + 1, N)
        if any(
            A[u][v] == A[u][k] + A[k][v]
            for k in range(N)
            if k != u and k != v
        )
    )
)

# 出力
print(ans)
