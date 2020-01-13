#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, W, C): (usize, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (l, r, p): (Vec<i64>, Vec<i64>, Vec<i64>) = {
        let (mut l, mut r, mut p) = (vec![], vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            l.push(iter.next().unwrap().parse().unwrap());
            r.push(iter.next().unwrap().parse().unwrap());
            p.push(iter.next().unwrap().parse().unwrap());
        }
        (l, r, p)
    };

    const INF: i64 = 1e18 as i64;
    let (L, R, P) = {
        let mut I = (0..N).collect::<Vec<_>>();
        I.sort_by_key(|&i| l[i]);
        let (mut L, mut R, mut P) = (
            (0..N).map(|i| l[I[i]]).collect::<Vec<_>>(),
            (0..N).map(|i| r[I[i]]).collect::<Vec<_>>(),
            (0..N).map(|i| p[I[i]]).collect::<Vec<_>>(),
        );
        L.push(W);
        R.push(W);
        P.push(INF);
        (L, R, P)
    };
    let mut res = INF;
    let mut a = 0;
    let mut c = 0;
    let mut q: std::collections::BinaryHeap<(i64, i64)> = std::collections::BinaryHeap::new();
    for i in 0..(N + 1) {
        while L[i] - a >= C {
            res = std::cmp::min(res, c);
            if let Some((x, y)) = q.pop() {
                a = -x;
                c -= y;
            } else {
                break;
            }
        }
        q.push((-R[i], P[i]));
        c += P[i];
    }
    let ans = res;

    println!("{}", ans);
}
