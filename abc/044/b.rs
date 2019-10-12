#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let w: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let mut c = std::collections::HashMap::new();
    for &i in &w { *(c.entry(i).or_insert(0)) += 1; }
    let ans = if c.values().all(|&num| num % 2 == 0) { "Yes" } else { "No" };

    println!("{}", ans);
}