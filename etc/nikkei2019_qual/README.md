# 全国統一プログラミング王決定戦予選

## A
カテゴリ: 数学

最大は min(A, B),  最小は max(0, A + B - N) である。

## C
カテゴリ: 貪欲法

高橋君が料理iを食べることで得られる利益はA[i]だが、青木さんにB[i]だけ得することを防いだと考えると A[i] + B[i] の価値がある。
青木さんからみた場合も同様。
したがって、A[i] + B[i] が大きい料理から食べればよい。

## D
カテゴリ: 動的計画法

f(v) を頂点vの深さとする。vの親をpとして、f(v) = max(f(p)) + 1 が成り立つ。
ただし、vが根ならば f(v) = 0 と定める。
f(p) < f(v) - 1 を満たす辺(p, v) をすべて除去すればよい。
