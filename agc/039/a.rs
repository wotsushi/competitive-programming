#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };
    let K: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let N = S.len();
    let ans = if S.iter().collect::<std::collections::HashSet<_>>().len() == 1 {
        N * K / 2
    } else if S[0] == S[N - 1] {
        let c = S[0];
        let l = (0..N).take_while(|&i| S[i] == c).count();
        let r = (0..N).rev().take_while(|&i| S[i] == c).count();
        let (m, _) = (l..(N - r)).fold((0, '-'), |(res, prev), i| if S[i] == prev { (res + 1, '-') } else { (res, S[i]) });
        l / 2 + m * K + (l + r) / 2 * (K - 1) + r / 2
    } else {
        let (m, _) = (0..N).fold((0, '-'), |(res, prev), i| if S[i] == prev { (res + 1, '-') } else { (res, S[i]) });
        m * K
    };

    println!("{}", ans);
}