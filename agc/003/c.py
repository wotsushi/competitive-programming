# 入力
N = int(input())
A = [int(input()) for _ in range(N)]

# 奇数番目の要素が偶数番目に小さい、または、
# 偶数番目の要素が奇数番目に小さいならばその要素に対して操作1を適用する必要がある
R = {a: i for i, a in enumerate(sorted(A))}
ans = sum(i % 2 != R[a] % 2 for i, a in enumerate(A)) // 2

# 出力
print(ans)
