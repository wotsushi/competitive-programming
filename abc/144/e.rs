#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K): (usize, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };
    let F: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    fn bis<P>(ok: i64, ng: i64, p: P) -> i64
        where P: Fn(i64) -> bool {
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
        B
    };
    let G = {
        let mut G = F.clone();
        G.sort();
        G.reverse();
        G
    };

    const INF: i64 = 1_000_000_000_000_000;
    let ans = bis(INF, -1, |c| (0..N).map(|i| std::cmp::max(0, B[i] - c / G[i])).sum::<i64>() <= K);

    println!("{}", ans);
}