# ABC009

## A
カテゴリ: 数学

解はceil(N / 2)である。

## B
カテゴリ: 実装

やるだけ。

## C
カテゴリ: 貪欲法

ヒントの通り、prefixをTにできるかを検査する。
このとき、Tは早い文字列から順に検査対象とする。
prefixをTにできるかの判定は先頭|T|文字について、Sの先頭|T|文字と異なる文字数を数える。
異なる文字について、先頭|T|文字の文字同士で交換できるものは交換する。
この方針により交換回数をK以下にできるならば検査結果はOKとなる。