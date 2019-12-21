#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let N = S.len();
    let ans = (0..N).filter(|&i| S[i] != S[N - i - 1]).count() / 2;

    println!("{}", ans);
}