# 入力
N = int(input())
A = list(map(int, input().split()))

# 重複しているカードに対して、ひたすら操作した結果が解である
m = len(set(A))
ans = m - (1 - m % 2)

# 出力
print(ans)
