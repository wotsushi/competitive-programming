#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, M, L): (usize, usize, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (A, B, C): (Vec<usize>, Vec<usize>, Vec<i64>) = {
        let (mut A, mut B, mut C) = (vec![], vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            A.push(iter.next().unwrap().parse().unwrap());
            B.push(iter.next().unwrap().parse().unwrap());
            C.push(iter.next().unwrap().parse().unwrap());
        }
        (A, B, C)
    };
    let Q: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (s, t): (Vec<usize>, Vec<usize>) = {
        let (mut s, mut t) = (vec![], vec![]);
        for _ in 0..Q {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            s.push(iter.next().unwrap().parse().unwrap());
            t.push(iter.next().unwrap().parse().unwrap());
        }
        (s, t)
    };

    const INF: i64 = 1_000_000_000_000_000;
    let mut dp = vec![vec![INF; N + 1]; N + 1];
    for i in 0..M {
        dp[A[i]][B[i]] = C[i];
        dp[B[i]][A[i]] = C[i];
    }
    for k in 1..(N + 1) { for i in 1..(N + 1) { for j in 1..(N + 1) { dp[i][j] = std::cmp::min(dp[i][j], dp[i][k] + dp[k][j]); }}}
    let mut dp2 = (0..(N + 1))
        .map(|i| (0..(N + 1))
            .map(|j| if dp[i][j] <= L { 1 } else { INF })
            .collect::<Vec<_>>()
        ).collect::<Vec<_>>();
    for k in 1..(N + 1) { for i in 1..(N + 1) { for j in 1..(N + 1) { dp2[i][j] = std::cmp::min(dp2[i][j], dp2[i][k] + dp2[k][j]); }}}

    let ans = (0..Q)
        .map(|i| if dp2[s[i]][t[i]] == INF { -1 } else { dp2[s[i]][t[i]] - 1 } )
        .map(|res| res.to_string())
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}