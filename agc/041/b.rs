#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, M, V, P): (usize, i64, i64, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
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
    let ans = bis(1, N as i64 + 1, |n| {
        let n = n as usize;
        let x = B[n - 1] + M;
        n <= P
            || (B[P - 1] <= x
                && B[(P - 1)..(n - 1)].iter().map(|&b| x - b).sum::<i64>()
                    >= M * (V - (P + N - n) as i64))
    });

    println!("{}", ans);
}
