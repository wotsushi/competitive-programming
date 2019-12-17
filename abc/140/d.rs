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
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let a = (0..N)
        .filter(|&i| {
            i >= 1 && S[i - 1] == 'L' && S[i] == 'L' || i + 1 < N && S[i] == 'R' && S[i + 1] == 'R'
        })
        .count();
    let m = S
        .iter()
        .map(|&s| s.to_string())
        .collect::<String>()
        .split(S[0])
        .filter(|&s| s != "")
        .count();
    let ans = if K >= m && S[0] != S[N - 1] {
        a + 2 * m - 1
    } else {
        a + 2 * std::cmp::min(m, K)
    };

    println!("{:?}", ans);
}
