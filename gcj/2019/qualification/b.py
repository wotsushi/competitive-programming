T = int(input())

for x in range(1, T + 1):
    # 入力
    N = int(input())
    P = input()

    # PのEとSを反転させた文字列が解
    y = ''.join(
        'E' if p == 'S' else
        'S'
        for p in P
    )

    # 出力
    print('Case #{}: {}'.format(x, y))
