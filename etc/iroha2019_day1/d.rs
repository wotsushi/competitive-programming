#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, X, Y): (usize, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let B = {
        let mut B = A.clone();
        B.sort_by_key(|b| -b);
        B
    };
    let D = X - Y + (0..(N / 2)).map(|i| B[2 * i] - B[2 * i + 1]).sum::<i64>();
    let ans = if D > 0 { "Takahashi" } else if D == 0 { "Draw" } else { "Aoki" };

    println!("{}", ans);
}