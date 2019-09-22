#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<Vec<i64>> = {
        let mut A = vec![];
        for _ in 0..2 {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            A.push(
                line.split_whitespace()
                    .map(|x| x.parse().unwrap())
                    .collect()
            );
        }
        A
    };

    let (_, ans) = (1..N).fold(
        (A[0][0], A[0][0] + A[1][0]),
        |(u, d), i| (u + A[0][i], std::cmp::max(u + A[0][i], d) + A[1][i])
    );

    println!("{}", ans);
}