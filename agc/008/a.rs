#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (x, y): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    const INF: i64 = 1_000_000_000_000_000;
    fn f(z: i64) -> i64 { if z >= 0 { z } else { INF } }
    let ans = *vec![f(y - x), f(x + y) + 1, f(-(x + y)) + 1, f(x - y) + 2]
        .iter()
        .min()
        .unwrap();

    println!("{}", ans);
}