# ARC074

## D
カテゴリ: 考察

N <= i <= 2N について、 A_1, A_2, ..., A_i から和が最大となるようにN個の整数を選んだとき、
その和をL[i] とする。
N + 1 <= i <= 2N + 1 について、 A_i, A_{i + 1}, ..., A_{3N} から和が最小となるようにN個の整数を選んだとき、
その和をR[i] とする。
解は、max(L[N] - R[N + 1], L[N + 1] - R[N + 2], ..., L[2N] + R[2N + 1]) である。