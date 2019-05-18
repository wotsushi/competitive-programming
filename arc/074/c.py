from math import floor, ceil
from itertools import chain

# 入力
H, W = map(int, input().split())

# ある1ピースを i*W または j*W となるように切ったときのS_max - S_minをすべて求める
ans = min(
    max(a, b, c) - min(a, b, c)
    for a, b, c in chain(
        (
            (i * W, (H - i) * floor(W / 2), (H - i) * ceil(W / 2))
            for i in range(1, H)
        ),
        (
            (i * W, floor((H - i) / 2) * W, ceil((H - i) / 2) * W)
            for i in range(1, H)
        ),
        (
            (j * H, (W - j) * floor(H / 2), (W - j) * ceil(H / 2))
            for j in range(1, W)
        ),
        (
            (j * H, floor((W - j) / 2) * H, ceil((W - j) / 2) * H)
            for j in range(1, W)
        ),
    )
)

# 出力
print(ans)
