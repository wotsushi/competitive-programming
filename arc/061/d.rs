#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W, N): (i64, i64, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (a, b): (Vec<i64>, Vec<i64>) = {
        let (mut a, mut b) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            a.push(iter.next().unwrap().parse().unwrap());
            b.push(iter.next().unwrap().parse().unwrap());
        }
        (a, b)
    };

    let p = (0..N)
        .map(|i| (a[i], b[i]))
        .collect::<std::collections::HashSet<_>>();
    let mut dp = vec![0; 10];
    for k in 0..N {
        let (y, x) = (a[k], b[k]);
        for u in std::cmp::max(1, y - 2)..(std::cmp::min(H - 2, y) + 1) {
            for l in std::cmp::max(1, x - 2)..(std::cmp::min(W - 2, x) + 1) {
                dp[(u..(u + 3))
                    .map(|i| (l..(l + 3)).filter(|&j| p.contains(&(i, j))).count())
                    .sum::<usize>()] += 1;
            }
        }
    }
    for i in 1..10 {
        dp[i] /= i as i64;
    }
    let ans = (0..10)
        .map(|i| {
            if i == 0 {
                ((H - 2) * (W - 2) - dp.iter().sum::<i64>()).to_string()
            } else {
                dp[i].to_string()
            }
        })
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}
