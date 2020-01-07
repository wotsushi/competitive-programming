#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let a: Vec<Vec<i64>> = {
        let mut a = vec![];
        for _ in 0..(N - 1) {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            a.push(
                line.split_whitespace()
                    .map(|x| x.parse().unwrap())
                    .collect(),
            );
        }
        a
    };

    static INF: i64 = 1e18 as i64;

    fn f(i: usize, g: &mut Vec<usize>, N: usize, a: &Vec<Vec<i64>>) -> i64 {
        if i == N {
            (0..N)
                .map(|i| {
                    ((i + 1)..N)
                        .map(|j| if g[i] == g[j] { a[i][j - i - 1] } else { 0 })
                        .sum::<i64>()
                })
                .sum::<i64>()
        } else {
            let mut res = -INF;
            for k in 0..3 {
                g[i] = k;
                res = std::cmp::max(res, f(i + 1, g, N, a));
            }
            res
        }
    }
    let ans = f(0, &mut vec![0; N], N, &a);

    println!("{}", ans);
}
