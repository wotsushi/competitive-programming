#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    const INF: i64 = 1e18 as i64;
    let s = A.iter().sum::<i64>();
    let (ans, _) = A[1..].iter().fold((INF, A[0]), |(res, acc), &a| {
        (std::cmp::min(res, (s - 2 * acc).abs()), acc + a)
    });

    println!("{}", ans);
}
