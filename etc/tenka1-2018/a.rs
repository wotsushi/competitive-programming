#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ans = if S.len() == 2 {
        S.iter().map(|&c| c).collect::<String>()
    } else {
        S.iter().rev().map(|&c| c).collect::<String>()
    };

    println!("{}", ans);
}
