#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ans = (1..S.len()).fold(0, |res, i| if S[i - 1] != S[i] { res + 1 } else { res });

    println!("{}", ans);
}