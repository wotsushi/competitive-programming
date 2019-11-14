#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let a = S.iter().filter(|&&s| s == 'a').count();
    let b = S.iter().filter(|&&s| s == 'b').count();
    let c = S.iter().filter(|&&s| s == 'c').count();
    let ans = if *vec![a, b, c].iter().max().unwrap() - *vec![a, b, c].iter().min().unwrap() <= 1 { "YES" } else { "NO" };

    println!("{}", ans);
}