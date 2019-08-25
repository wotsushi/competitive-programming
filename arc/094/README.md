# ARC094

## D
カテゴリ: 数え上げ

A_i <= B_i と仮定して一般性を失わない。
k < A_i ならば kx < A_i B_i を満たす x > B_i が存在し、各kについて、相異なるxを選ぶことができる。
A_i = B_i ならば数え上げはここまでである。
以降、A_i < B_i を仮定する。
A_i <= k < floor(sqrt(A_i B_i)) ならば kx < A_i B_i を満たす k < x < B_i が存在し、
各kについて、相異なるxを選ぶことができる。
k = floor(sqrt(A_i B_i)) ならば kx < A_i B_i を満たすx >= k は x = k または k + 1 のみである。
