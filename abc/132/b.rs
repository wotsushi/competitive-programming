#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let n: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let p: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let ans = (1..(n - 1))
        .filter(|&i| p[i - 1] < p[i] && p[i] < p[i + 1] || p[i - 1] > p[i] && p[i] > p[i + 1])
        .count();

    println!("{}", ans);
}
