#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    const INF: i64 = 1_000_000_000_000_000;
    let M = (N as f64).sqrt() as i64;
    let ans = (1..(M + 1))
        .map(|i| if N % i == 0 { i + N / i - 2 } else { INF })
        .min()
        .unwrap();

    println!("{}", ans);
}