#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let A: Vec<Vec<char>> = (0..H).map(|_| {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    }).collect();

    const INF: i64 = 1_000_000_000;
    let mut q = std::collections::VecDeque::new();
    let mut dp = vec![vec![INF; W]; H];
    for i in 0..H {
        for j in 0..W {
            if A[i][j] == '#' {
                q.push_back((0, i, j));
                dp[i][j] = 0;
            }
        }
    }
    while let Some((d, i, j)) = q.pop_front() {
        for (u, v) in vec![(i + 1, j), (i.saturating_sub(1), j), (i, j + 1), (i, j.saturating_sub(1))] {
            if u < H && v < W && dp[u][v] > d + 1 {
                dp[u][v] = d + 1;
                q.push_back((d + 1, u, v));
            }
        }
    }
    let ans = dp.iter().map(|a| a.iter().max().unwrap()).max().unwrap();

    println!("{}", ans);
}