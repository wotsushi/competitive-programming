# ARC091

## E
カテゴリ: 構築

AB < N または A + B > N + 1 ならば　構築不可。
A >= B を仮定する。

N % A  > B - floor(N / A) ならば
N - A + 1, N - A + 2, ..., N,
N - 2A + 1, N - 2A + 2, ..., N - A,
...,
N - floor(N / A)A + 1, N - floor(N / A)A + 2, ..., N - (floor(N / A) + 1)A,
B - floor(N / A), B - floor(N / A) + 1, ..., N - floor(N / A)A
B - floor(N / A) - 1, B - floor(N / A) - 2, ..., 1

N % A <= B - floor(N / A) ならば
N - A + 1, N - A + 2, ..., N,
N - 2A + 1, N - 2A + 2, ..., N - A,
...,
N - (floor(N / A) - 1)A + 1, N - (floor(N / A) - 1)A + 2, ..., N - floor(N / A)A,
B - floor(N / A) + 1, B - floor(N / A) + 2, ..., N - (floor(N / A) - 1)A
B - floor(N / A), B - floor(N / A) - 1, ..., 1

A < B の場合も同様に構築できる。
