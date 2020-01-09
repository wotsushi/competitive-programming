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
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let A: Vec<Vec<i64>> = {
        let mut A = vec![];
        for _ in 0..H {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            A.push(
                line.split_whitespace()
                    .map(|x| x.parse().unwrap())
                    .collect(),
            );
        }
        A
    };

    let d = |i_from: usize, j_from: usize| {
        const INF: i64 = 1e18 as i64;
        let mut dp = vec![vec![INF; W]; H];
        let mut q = std::collections::BinaryHeap::new();
        dp[i_from][j_from] = 0;
        q.push((0, (i_from, j_from)));
        while let Some((x, (i, j))) = q.pop() {
            let x = -x;
            for &(di, dj) in &[(1, 0), (0, 1), (-1, 0), (0, -1)] {
                let u = i as i64 + di;
                let v = j as i64 + dj;
                if 0 <= u && u < H as i64 && 0 <= v && v < W as i64 {
                    let u = u as usize;
                    let v = v as usize;
                    if x + A[u][v] < dp[u][v] {
                        dp[u][v] = x;
                        q.push((-(dp[u][v] + A[u][v]), (u, v)));
                    }
                }
            }
        }
        dp
    };
    let dp = d(H - 1, 0);
    let dp2 = d(H - 1, W - 1);
    let dp3 = d(0, W - 1);

    let ans = (0..H)
        .map(|i| {
            (0..W)
                .map(|j| dp[i][j] + dp2[i][j] + dp3[i][j] + A[i][j])
                .min()
                .unwrap()
        })
        .min()
        .unwrap();

    println!("{}", ans);
}
