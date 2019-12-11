#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (c, a): (Vec<char>, Vec<usize>) = {
        let (mut c, mut a) = (vec![], vec![]);
        for _ in 0..(2 * N) {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            c.push(iter.next().unwrap().chars().collect::<Vec<_>>()[0]);
            a.push(iter.next().unwrap().parse().unwrap());
        }
        (c, a)
    };
    let mut W = vec![0; N + 1];
    let mut B = vec![0; N + 1];
    for i in 0..(2 * N) {
        if c[i] == 'W' {
            W[a[i]] = i;
        }
        if c[i] == 'B' {
            B[a[i]] = i;
        }
    }

    const INF: usize = 1_000_000_000_000_000;
    let mut dp = vec![vec![INF; N + 1]; N + 1];
    dp[0][0] = 0;
    let mut x = vec![vec![0; N + 1]; N + 1];
    for i in 0..(N + 1) {
        x[i][0] = (0..W[i]).filter(|&k| c[k] == 'W' && a[k] > i).count()
            + (0..W[i]).filter(|&k| c[k] == 'B').count();
        for j in 1..(N + 1) {
            x[i][j] = if B[j] < W[i] {
                x[i][j - 1] - 1
            } else {
                x[i][j - 1]
            };
        }
    }
    let mut y = vec![vec![0; N + 1]; N + 1];
    for j in 0..(N + 1) {
        y[0][j] = (0..B[j]).filter(|&k| c[k] == 'B' && a[k] > j).count()
            + (0..B[j]).filter(|&k| c[k] == 'W').count();
        for i in 1..(N + 1) {
            y[i][j] = if W[i] < B[j] {
                y[i - 1][j] - 1
            } else {
                y[i - 1][j]
            };
        }
    }
    for i in 0..(N + 1) {
        for j in 0..(N + 1) {
            dp[i][j] = if i == 0 && j == 0 {
                0
            } else if i == 0 {
                dp[i][j - 1] + y[i][j]
            } else if j == 0 {
                dp[i - 1][j] + x[i][j]
            } else {
                std::cmp::min(dp[i][j - 1] + y[i][j], dp[i - 1][j] + x[i][j])
            };
        }
    }
    let ans = dp[N][N];

    println!("{}", ans);
}
