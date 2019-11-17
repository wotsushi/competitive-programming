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
            iter.next().unwrap().parse().unwrap()
        )
    };
    let H: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let h = {
        let mut h = H.clone();
        h.insert(0, 0);
        h
    };
    const INF: i64 = 1_000_000_000_000;
    let M = N - K;
    let mut dp = vec![vec![INF; N + 1]; M + 1];
    dp[0][0] = 0;
    for i in 1..(N + 1) { for k in (1..(M + 1)).rev() { dp[k][i] = (0..i).map(|j| dp[k - 1][j] + std::cmp::max(0, h[i] - h[j])).min().unwrap(); } }
    let ans = *dp[M].iter().min().unwrap();

    println!("{}", ans);
}