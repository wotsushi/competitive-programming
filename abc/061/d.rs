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
    let (a, b, c): (Vec<usize>, Vec<usize>, Vec<i64>) = {
        let (mut a, mut b, mut c) = (vec![], vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            a.push(iter.next().unwrap().parse().unwrap());
            b.push(iter.next().unwrap().parse().unwrap());
            c.push(iter.next().unwrap().parse().unwrap());
        }
        (a, b, c)
    };

    const INF: i64 = 1e14 as i64;
    let mut dp = vec![INF; N + 1];
    dp[1] = 0;
    for k in 0..N {
        for i in 0..M {
            dp[b[i]] = std::cmp::min(dp[b[i]], dp[a[i]] + (-c[i]))
        }
    }
    for k in 0..N {
        for i in 0..M {
            if dp[a[i]] + (-c[i]) < dp[b[i]] {
                dp[b[i]] = -INF;
            }
        }
    }
    let ans = if dp[N] <= -INF {
        "inf".to_string()
    } else {
        (-dp[N]).to_string()
    };

    println!("{}", ans);
}
