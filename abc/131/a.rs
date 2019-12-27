#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ans = if (0..3).any(|i| S[i] == S[i + 1]) {
        "Bad"
    } else {
        "Good"
    };

    println!("{}", ans);
}