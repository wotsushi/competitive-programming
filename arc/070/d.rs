#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let a: Vec<usize> = {
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

    let b = {
        let mut b = a.clone();
        b.push(0);
        b.sort();
        b
    };
    let ans = bis(0, (N + 1) as i64, |m| {
        let m = m as usize;
        let mut dp = vec![false; K];
        dp[0] = true;
        for i in 1..(N + 1) {
            if i != m {
                let x = b[i];
                for j in (x..K).rev() {
                    dp[j] |= dp[j - x];
                }
            }
        }
        let s = if K >= b[m] { K - b[m] } else { 0 };
        !dp[s..].iter().any(|&r| r)
    });

    println!("{}", ans);
}
