#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, M): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (a, b, c) = {
        let (mut a, mut b, mut c) = (vec![], vec![], vec![]);
        for _ in 0..M {
            let (x, y): (i64, usize) = {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                let mut iter = line.split_whitespace();
                (
                    iter.next().unwrap().parse().unwrap(),
                    iter.next().unwrap().parse().unwrap(),
                )
            };
            let z: Vec<usize> = {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                line.split_whitespace()
                    .map(|x| x.parse().unwrap())
                    .collect()
            };
            a.push(x);
            b.push(y);
            c.push(z);
        }
        (a, b, c)
    };

    const INF: i64 = 1e15 as i64;
    let P = 1 << N;
    let mut dp = vec![INF; P];
    dp[0] = 0;
    for k in 0..M {
        let s = c[k].iter().map(|&x| 1 << (x - 1)).sum::<usize>();
        for i in 0..P {
            dp[i | s] = std::cmp::min(dp[i | s], dp[i] + a[k]);
        }
    }
    let ans = if dp[P - 1] < INF { dp[P - 1] } else { -1 };

    println!("{}", ans);
}
