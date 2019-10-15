#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let s: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let N = s.len();
    let l = (0..N).find(|&i| s[i] == 'A').unwrap();
    let r = (0..N).rev().find(|&i| s[i] == 'Z').unwrap();
    let ans = r - l + 1;

    println!("{}", ans);
}
