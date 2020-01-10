#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<Vec<usize>> = {
        let mut A = vec![];
        for _ in 0..N {
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

    let B = {
        let mut B = vec![];
        for i in 0..N {
            for j in 0..6 {
                B.push((A[i][j], i));
            }
        }
        B.sort();
        B.reverse();
        B
    };
    let mut dp = vec![0.0; N];
    let mut j = 0;
    for &(b, i) in &B {
        dp[i] += (dp[j] + 1.0) / 6.0;
        if dp[i] > dp[j] {
            j = i;
        }
    }

    let ans = dp[j] + 1.0;
    println!("{}", ans);
}
