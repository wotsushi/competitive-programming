# AGC008

## A
カテゴリ: 実装

以下のうち最適なものを解とすればよい。
* ボタンAだけ押す
* ボタンBを押した後、ボタンAを押し続ける
* ボタンAを押し続けた後、ボタンBを押す
* ボタンBを押した後、ボタンAを押し続け、ボタンBを押す

## B
カテゴリ: しゃくとり法

作成可能なマスの最終形について考える。
連続するKマスが同色であるような箇所が存在するならば、作成可能である。
したがって、正の値が書かれたマスのみ黒で塗った場合の点数をもとに、連続するKマスを白または黒で塗った場合の点数を求めればよい。

## C
カテゴリ: 構築

T, S, Z型のテトロミノは使いものにならない（必ず隙間ができる）。
O型のテトロミノは素直に並べるだけでよい。
I, J, L型のテトロミノは以下の使い方がある。

* 同型のテトロミノを二つ組み合わせて横4マスの長方形を作る
* それぞれ1個ずつ組み合わせて横6マスの長方形を作る

I, J, L型のテトロミノのうち、個数が奇数であるものが2個以上存在する、かつ、
それぞれの個数が1個以上ならば、後者の使い方で長方形を一つ作る。
残ったテトロミノは前者の使い方で可能な限り長方形を作ればよい。
以上より、R を a_I % 2 + a_J % 2 + a_L % 2 >= 2 と min(A_I, a_J, a_L) >= 1 を満たすならば1,
そうでなければ 0 をとる値として、
解は a_O + 2floor((a_I - R) / 2) + 2floor((a_J - R) / 2) + 2floor((a_L - R) / 2) + 3R
である。