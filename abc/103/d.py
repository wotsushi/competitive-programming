from functools import reduce
from operator import itemgetter

N, M = map(int, input().split())
a, b = (
    zip(*(map(int, input().split()) for _ in range(M))) if M else
    ((), ())
)

# bについてソートし、橋を取り除く必要があれば可能な限り東の橋を取り除く
ans, _ = reduce(
    lambda acc, q: (
        (acc[0] + 1, q[1]) if q[0] >= acc[1] else
        acc
    ),
    sorted(zip(a, b), key=itemgetter(1)),
    (0, 0)
)

print(ans)
