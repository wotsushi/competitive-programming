#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: String = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().to_string()
    };

    let ans = if S.starts_with("YAKI") { "Yes" } else { "No" };

    println!("{}", ans);
}