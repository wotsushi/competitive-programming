# AGC012

## B
カテゴリ: 探索

最後の操作から順に処理する。このとき、既に色が塗られている頂点は色を塗らないとする。
色を塗る操作はDFSで再帰的に実現できる。
これを愚直に実装すると O(NQ) の時間を要するため、以下の通り計算を省く。
頂点vから距離d以内の頂点に対する操作を過去に実行したことがあるならば、その頂点に対する操作を実行しない。
各操作の距離は10以下なので O(N + Q) の時間で解を計算できる。