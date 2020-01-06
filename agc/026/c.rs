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

    let mut used = std::collections::HashSet::new();
    let mut res = 0;
    for p in 0..(1 << N) {
        let mut s = vec![];
        let mut tail = vec![];
        for i in 0..N {
            if (p >> i) & 1 == 1 {
                s.push(S[i]);
            } else {
                tail.push(S[i]);
            }
        }
        while let Some(c) = tail.pop() {
            s.push(c);
        }
        if !used.contains(&s) {
            let mut dp = vec![vec![0; N + 1]; N + 1];
            dp[0][0] = 1i64;
            for i in 0..(N + 1) {
                for j in 0..(N + 1) {
                    let k = i + j;
                    if i > 0 && S[k - 1] == s[i - 1] {
                        dp[i][j] += dp[i - 1][j]
                    }
                    if j > 0 && S[k - 1] == s[N - j] {
                        dp[i][j] += dp[i][j - 1]
                    }
                }
            }
            res += dp[N][N];
            used.insert(s);
        }
    }
    let ans = res;

    println!("{}", ans);
}