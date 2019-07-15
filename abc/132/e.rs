macro_rules! get {
    (Vec<$t:ty>) => {
        {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.split_whitespace()
                .map(|t| t.parse::<$t>().unwrap())
                .collect::<Vec<_>>()
        }
    };
    ($t:ty) => {
        {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse::<$t>().unwrap()
        }
    };
    ($($t:ty),*) => {
        {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            (
                $(iter.next().unwrap().parse::<$t>().unwrap(),)*
            )
        }
    };
    ($t:ty; $n:expr) => {
        (0..$n).map(|_|
            get!($t)
        ).collect::<Vec<_>>()
    };
    ($($t:ty),*; $n:expr) => {
        (0..$n).map(|_|
            get!($($t),*)
        ).collect::<Vec<_>>()
    };
}

use std::collections::VecDeque;

fn main() {
    let (N, M) = get!(usize, usize);
    let (u, v): (Vec<_>, Vec<_>) = get!(usize, usize; M).into_iter().unzip();
    let (S, T) = get!(usize, usize);

    // 何歩目かを含めた状態グラフを作成し、BFSにより解を求める
    let mut G = vec!(vec!(); 3 * N + 1);
    for (x, y) in u.into_iter().zip(v.into_iter()) {
        G[x].push((y + N, 0));
        G[x + N].push((y + 2 * N, 0));
        G[x + 2 * N].push((y, 1));
    }
    let mut q = VecDeque::new();
    let mut dp = vec!(-1; 3 * N + 1);
    q.push_back(S);
    dp[S] = 0;
    while !q.is_empty() {
        let i = q.pop_front().unwrap();
        for (x, w) in G[i].clone() {
            if dp[x] == -1 {
                q.push_back(x);
                dp[x] = dp[i] + w;
            }
        }
    }
    let ans = dp[T];

    println!("{}", ans);
}
