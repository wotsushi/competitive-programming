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

    let mut res = vec![(0..N)
        .map(|i| if i % 2 == 0 { A[i] } else { -A[i] })
        .sum::<i64>()];
    for i in 0..(N - 1) {
        let x = res[i] / 2;
        res.push(2 * (A[i] - x));
    }
    let ans = res
        .iter()
        .map(|&x| x.to_string())
        .collect::<Vec<_>>()
        .join(" ");

    println!("{}", ans);
}
