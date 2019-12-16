#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let mut dp = vec![vec![0; N + 1]; N + 1];
    for i in (1..N).rev() {
        for j in (0..i).rev() {
            dp[j][i] = if S[j] == S[i] {
                std::cmp::min(i - j, dp[j + 1][i + 1] + 1)
            } else {
                0
            };
        }
    }
    let ans = (0..(N - 1))
        .map(|i| ((i + 1)..N).map(|j| dp[i][j]).max().unwrap())
        .max()
        .unwrap();

    println!("{}", ans);
}
