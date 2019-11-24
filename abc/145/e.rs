#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, T): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (A, B): (Vec<usize>, Vec<usize>) = {
        let (mut A, mut B) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            A.push(iter.next().unwrap().parse().unwrap());
            B.push(iter.next().unwrap().parse().unwrap());
        }
        (A, B)
    };

    let I = {
        let mut I = (0..N).collect::<Vec<_>>();
        I.sort_by_key(|&i| A[i]);
        I
    };
    let mut dp = vec![0; T + 1];
    for &i in &I {
        dp[T] = std::cmp::max(dp[T], *dp[0..T].iter().max().unwrap() + B[i]);
        for k in (A[i]..T).rev() {
            dp[k] = std::cmp::max(dp[k], dp[k - A[i]] + B[i]);
        }
    }
    let ans = dp[T];

    println!("{}", ans);
}
