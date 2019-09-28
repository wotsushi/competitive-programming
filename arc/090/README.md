# ARC090

## A
カテゴリ: 数学

解は (X - A) % B である。

## B
カテゴリ: 全探索

A, B, C は50以下なので、全探索でよい。

## C
カテゴリ: 動的計画法

移動可能な方向は右または下に限るため、DAGとみなせる。
DAGなので自明にDPできる。

## D
カテゴリ: 探索

各情報を重み付き有向グラフに対応させて考えたくなる。
具体的には、L_i から R_i に対する重みがD_iである有向辺とR_iからL_iに対する重みが-D_iである有向辺から成るグラフGを考える。
適当な頂点rを一つ選び、その座標を0と決め打つ。
rを始点として深さ優先探索により矛盾が生じないことを確かめればよい。
ここで、DAGは連結でない可能性があることに注意。
その場合、各成分ごとにrを選び、矛盾がないことを確かめる必要がある。