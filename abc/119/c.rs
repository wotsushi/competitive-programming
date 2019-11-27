#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, A, B, C): (usize, i64, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let l: Vec<i64> = (0..N)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse().unwrap()
        })
        .collect();
    static INF: i64 = 1_000_000_000_000;

    fn f(i: usize, x: &Vec<i64>, c: &Vec<i64>, N: usize, X: &Vec<i64>, l: &Vec<i64>) -> i64 {
        if i == N && c.iter().all(|&a| a >= 1) {
            (0..3)
                .map(|i| (X[i] - x[i]).abs() + 10 * (c[i] - 1))
                .sum::<i64>()
        } else if i == N && c.iter().any(|&a| a == 0) {
            INF
        } else {
            *vec![
                f(
                    i + 1,
                    &vec![x[0] + l[i], x[1], x[2]],
                    &vec![c[0] + 1, c[1], c[2]],
                    N,
                    X,
                    l,
                ),
                f(
                    i + 1,
                    &vec![x[0], x[1] + l[i], x[2]],
                    &vec![c[0], c[1] + 1, c[2]],
                    N,
                    X,
                    l,
                ),
                f(
                    i + 1,
                    &vec![x[0], x[1], x[2] + l[i]],
                    &vec![c[0], c[1], c[2] + 1],
                    N,
                    X,
                    l,
                ),
                f(i + 1, x, c, N, X, l),
            ]
            .iter()
            .min()
            .unwrap()
        }
    }
    let ans = f(0, &vec![0, 0, 0], &vec![0, 0, 0], N, &vec![A, B, C], &l);

    println!("{}", ans);
}
