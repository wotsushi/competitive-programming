#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ans = if S.iter().all(|&s| s.is_digit(10)) {
        (2 * S
            .iter()
            .map(|&s| s.to_digit(10).unwrap())
            .fold(0, |acc, d| 10 * acc + d))
        .to_string()
    } else {
        "error".to_string()
    };

    println!("{}", ans);
}
