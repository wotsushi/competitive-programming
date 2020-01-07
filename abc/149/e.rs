#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, M): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    fn bis<P: Fn(i64) -> bool>(ok: i64, ng: i64, p: P) -> i64 {
        let mid = (ok + ng) / 2;
        if (ok - ng).abs() == 1 {
            ok
        } else if p(mid) {
            bis(mid, ng, p)
        } else {
            bis(ok, mid, p)
        }
    }

    let B = {
        let mut B = A.clone();
        B.sort();
        B.reverse();
        B
    };
    let mut acc = vec![0];
    for i in 0..N {
        let s = acc[i] + B[i];
        acc.push(s);
    }
    let f = |m| {
        (0..N).fold((0, 0), |(c, s), i| {
            if 2 * B[i] < m {
                (c, s)
            } else {
                let i = i as i64;
                let j = bis(i, N as i64, |k| {
                    k == i - 1 || B[i as usize] + B[k as usize] >= m
                });
                if j == i - 1 {
                    (c, s)
                } else {
                    let q = j - i;
                    (
                        c as i64 + 2 * q + 1,
                        s + 2 * q * B[i as usize] + 2 * (acc[(j + 1) as usize] - acc[i as usize]),
                    )
                }
            }
        })
    };
    const INF: i64 = 1e12 as i64;
    let L = bis(1, INF, |m| {
        let (c, _) = f(m);
        c >= M as i64
    });
    let (c, s) = f(L);
    let ans = s - (c - M as i64) * L;

    println!("{}", ans);
}
