import sys
sys.setrecursionlimit(2*10**5)

# 入力
N, M = map(int, input().split())
A, B = zip(*(map(int, input().split()) for _ in range(M)))

# 隣接リスト表現のグラフに変換
E = [[] for _ in range(N + 1)]
for a, b in zip(A, B):
    E[a].append(b)
    E[b].append(a)

# 訪れたことがあるかどうかのフラグ
v = [i == 1 for i in range(N + 1)]


# 訪れたことのない頂点を深さ優先探索する
def dfs(i, p):
    for j in E[i]:
        if not v[j]:
            v[j] = True
            p.append(j)
            return dfs(j, p)
    else:
        return p


# Hamiltonish Path を求める
p = list(reversed(dfs(1, []))) + [1] + dfs(1, [])

# 出力
ans = '{}\n{}'.format(len(p), ' '.join(map(str, p)))
print(ans)
