# 全国統一プログラミング王決定戦予選

## D
カテゴリ: 動的計画法

f(v) を頂点vの深さとする。vの親をpとして、f(v) = max(f(p)) + 1 が成り立つ。
ただし、vが根ならば f(v) = 0 と定める。
f(p) < f(v) - 1 を満たす辺(p, v) をすべて除去すればよい。