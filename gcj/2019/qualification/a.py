T = int(input())

for x in range(1, T + 1):
    # 入力
    N = int(input())

    # Nの各桁の値を-1する。ただし、0はそのまま、5は3とする
    M = int(
        ''.join(
            '0' if d == '0' else
            '3' if d == '5' else
            str(int(d) - 1)
            for d in str(N)
        )
    )
    # M = 0 ならば N の各桁は0または1なので、(A, B) = (1, N - 1)
    # M > 0 ならば M, N - M の各桁に 4 を含まないように M を定めているので
    # (A, B) = (N, N - M)
    A = 1 if M == 0 else M
    B = N - A

    # 出力
    print('Case #{}: {} {}'.format(x, A, B))
