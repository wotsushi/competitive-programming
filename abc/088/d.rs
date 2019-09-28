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
    let s: Vec<Vec<char>> = (0..H).map(|_| {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    }).collect();

    let mut q = std::collections::VecDeque::new();
    let mut dp = vec![vec![-1; W]; H];
    q.push_back((0, 0));
    dp[0][0] = 0;
    while !q.is_empty() {
        let (i, j) = q.pop_front().unwrap();
        for (di, dj) in vec![(1, 0), (0, 1), (-1, 0), (0, -1)] {
            let (i2, j2) = (i + di, j + dj);
            if 0 <= i2 && i2 < (H as i64) && 0 <= j2 && j2 < (W as i64) &&
                dp[i2 as usize][j2 as usize] == -1 && s[i2 as usize][j2 as usize] == '.' {
                dp[i2 as usize][j2 as usize] = dp[i as usize][j as usize] + 1;
                q.push_back((i2, j2));
            }
        }
    }
    let ans = if dp[H - 1][W - 1] == -1 {
        -1
    } else {
        let w = (0..H).map(|i| (0..W).filter(|&j| s[i][j] == '.').count() as i64).sum::<i64>();
        w - dp[H - 1][W - 1] - 1
    };

    println!("{}", ans);
}
