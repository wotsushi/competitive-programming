#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let v: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    // 価値の小さい具材から順に鍋に入れればよい
    let u = {
        let mut u = v.clone();
        u.sort();
        u
    };
    let ans = u[1..].iter()
        .map(|&x| x as f64)
        .fold(u[0] as f64, |acc, x| (acc + x) / 2.0);

    println!("{}", ans);
}
