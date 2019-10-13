#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let s: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let m = s.len();
    let ans = if m % 2 == 0 && s[0] == s[m - 1] || m % 2 == 1 && s[0] != s[m - 1] { "First" } else { "Second" };

    println!("{}", ans);
}