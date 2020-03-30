# ABC038

## D
カテゴリ: 動的計画法

dp[i] をi個の箱を使う際の縦サイズの最小値として、横サイズが小さい箱から順にdpを更新すればよい。
横サイズが同一の箱に注意。dp2[i]をdp[i]を達成するときの横サイズとして、真に大きいかチェックするとよい。
また、更新順序にも注意。横サイズが同一の箱は縦サイズが大きい順に処理すると楽。