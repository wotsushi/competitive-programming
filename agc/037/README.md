# AGC037

## A
カテゴリ: 貪欲法

各S_iは高々2文字となるように分割可能である。
S_{i - 1} が S_i と異なるようになるべくS_iの長さが小さくなるように貪欲に分割すればよい。
なお、同一文字が3n + 2文字連続続く場合は、その箇所の先頭は2文字とする。

## B
カテゴリ: 数え上げ

番号の大きいボールから順に以下を処理する。

1. そのボールの色以外のボールを2個持っている人がいれば、それらのうち誰かにボールを割り当てる
2. そうでない場合: そのボールの色以外のボールを1個持っている人がいれば、それらのうち誰かにボールを割り当てる
3. そうでない場合: ボールを持っていない人のうち誰かにボールを割り当てる

この処理の過程で割り当てることができる人が複数いる場合、その分だけ分配方法は乗算される。
