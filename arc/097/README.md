# ARC097

## D
カテゴリ: UnionFind木

UnionFind木により x_i と y_i を結合する。
各連結成分について、p_i = i にできる数を数えればよい。

## E
カテゴリ: 動的計画法

白いボールを（値が小さいボールから順に）i個、黒いボールを（値が小さいボールから順に）j個、
条件を満たす並び順で左側に置いた状態をS[i][j]で表す。
dp[i][j]を状態S[i][j]に到達するのに要する最小交換回数とする。
各色の各数字のボールkについて、S[i][j]の状態でkを左側に運ぶための交換回数を前計算しておくことで、dp[i][j]はdp[i - 1][j]とdp[i][j - 1]からO(1)で計算できる。
