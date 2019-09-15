#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, D): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let X: Vec<Vec<i64>> = {
        let mut X = vec![];
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            X.push(
                line.split_whitespace()
                    .map(|x| x.parse().unwrap())
                    .collect()
            );
        }
        X
    };

    let sq = (0..1000)
        .map(|i| i * i)
        .collect::<std::collections::HashSet<i64>>();
    let ans = (0..(N - 1))
        .map(|i| ((i + 1)..N)
            .map(|j| (0..D)
                .map(|k| (X[i][k] - X[j][k]).pow(2))
                .sum::<i64>())
            .filter(|&d| sq.contains(&d))
            .count())
        .sum::<usize>();

    println!("{}", ans);
}
