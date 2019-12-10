#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    const INF: i64 = 1e15 as i64;
    let N = S.len() + 1;
    let mut R = S
        .iter()
        .rev()
        .scan(0, |state, &s| {
            *state = if s == '>' { *state + 1 } else { 0 };
            Some(*state)
        })
        .collect::<Vec<_>>();
    R.reverse();
    let mut res = vec![0; N];
    res[0] = R[0];
    for i in 0..(N - 2) {
        res[i + 1] = match (S[i], S[i + 1]) {
            ('<', '<') => res[i] + 1,
            ('<', '>') => std::cmp::max(res[i] + 1, R[i + 1]),
            ('>', '<') => 0,
            _ => R[i + 1],
        };
    }
    res[N - 1] = if S[N - 2] == '>' { 0 } else { res[N - 2] + 1 };
    let ans = res.iter().sum::<i64>();

    println!("{}", ans);
}
