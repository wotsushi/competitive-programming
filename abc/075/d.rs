#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (x, y): (Vec<i64>, Vec<i64>) = {
        let (mut x, mut y) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            x.push(iter.next().unwrap().parse().unwrap());
            y.push(iter.next().unwrap().parse().unwrap());
        }
        (x, y)
    };

    const INF: i64 = 4e18 as i64;

    let ans = (0..N).map(|i| {
        (0..N).map(|j| {
            (0..N).map(|k| {
                (0..N).map(|l| {
                    if (0..N).filter(|&m| x[i] <= x[m] && x[m] <= x[j] && y[k] <= y[m] && y[m] <= y[l]).count() >= K {
                        (x[i] - x[j]).abs() * (y[k] - y[l]).abs()
                    } else {
                        INF
                    }
                }).min().unwrap()
            }).min().unwrap()
        }).min().unwrap()
    }).min().unwrap();

    println!("{}", ans);
}