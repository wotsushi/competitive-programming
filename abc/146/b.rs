#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ascii_uppercase: Vec<_> = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".chars().collect();

    let ans = S
        .iter()
        .map(|&c| {
            ascii_uppercase[((0..26).find(|&i| ascii_uppercase[i] == c).unwrap() + N) % 26]
                .to_string()
        })
        .collect::<Vec<_>>()
        .join("");

    println!("{}", ans);
}
