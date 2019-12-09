#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let A: Vec<Vec<i64>> = {
        let mut A = vec![];
        for _ in 0..H {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            A.push(
                line.split_whitespace()
                    .map(|x| x.parse().unwrap())
                    .collect(),
            );
        }
        A
    };
    let B: Vec<Vec<i64>> = {
        let mut B = vec![];
        for _ in 0..H {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            B.push(
                line.split_whitespace()
                    .map(|x| x.parse().unwrap())
                    .collect(),
            );
        }
        B
    };

    let S = 80 * 160;
    let mut dp = vec![vec![vec![false; S + 1]; W + 1]; H + 1];
    dp[0][1][0] = true;
    for i in 0..H {
        for j in 0..W {
            let d = (A[i][j] - B[i][j]).abs() as usize;
            for k in 0..(S + 1) {
                dp[i + 1][j + 1][k] = (k + d <= S && (dp[i][j + 1][k + d] || dp[i + 1][j][k + d]))
                    || (k >= d && (dp[i][j + 1][k - d] || dp[i + 1][j][k - d]))
                    || (d >= k && (dp[i][j + 1][d - k] || dp[i + 1][j][d - k]));
            }
        }
    }
    let ans = (0..(S + 1)).find(|&k| dp[H][W][k]).unwrap();

    println!("{}", ans);
}
