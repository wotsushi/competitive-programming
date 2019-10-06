#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let S: Vec<Vec<char>> = (0..N).map(|_| {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    }).collect();

    // グラフが二部グラフならば真を返す
    fn f(i: usize, c: i64, cs: &mut Vec<i64>, N: usize, S: &Vec<Vec<char>>) -> bool {
        if cs[i] != 0 {
            c == cs[i]
        } else {
            cs[i] = c;
            (0..N).all(|j| S[i][j] == '0' || f(j, -c, cs, N, S))
        }
    }
    let mut cs = vec![0; N];
    let ans = if f(0, 1, &mut cs, N, &S) {
        const INF: i64 = 1_000_000_000;
        let mut dp = vec![vec![INF; N]; N];
        for i in 0..N { dp[i][i] = 0; }
        for i in 0..N { for j in 0..N { if S[i][j] == '1' { dp[i][j] = 1; } } }
        for k in 0..N { for i in 0..N { for j in 0..N { dp[i][j] = std::cmp::min(dp[i][j], dp[i][k] + dp[k][j]); } } }
        1 + (0..N).map(|i| *dp[i].iter().max().unwrap()).max().unwrap()
    } else {
        -1
    };

    println!("{}", ans);
}