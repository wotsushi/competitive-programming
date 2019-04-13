# 入力
T, N, M = map(int, input().split())

for x in range(T):
    # 解の候補集合
    D = set(range(1, M + 1))
    # 各クエリについて、すべての風車の羽の枚数は一定とする。
    # さらに、各クエリの羽の枚数について、最小公倍数が M の最大値である
    #  10**6 より大きくなるように各クエリを送信する
    for q in (11, 13, 14, 15, 16, 17, 18):
        print(
            ' '.join(str(q) for _ in range(18)),
            flush=True
        )
        Y = list(map(int, input().split()))
        D &= {s for s in range(sum(Y), M + 1, q)}
    # Dはシングルトンである
    ans = next(iter(D))
    # 出力
    print(ans, flush=True)
    # ジャッジ
    V = int(input())
    if V == -1:
        break
