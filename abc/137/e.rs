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

use std::cmp;

fn main() {
    let (N, M, P) = get!(usize, usize, i64);
    let ABC = get!(usize, usize, i64; M);

    // ベルマンフォード法により解を求める
    let INF = 1000000000000;
    let mut dp = vec!(INF; N + 1);
    dp[1] = 0;
    for k in 0..2*N {
        for i in 0..M {
            let (a, b, c) = ABC[i];
            let w = P - c;
            if dp[a] < INF && dp[b] > dp[a] + w {
                dp[b] = dp[a] + w;
                if k >= N - 1 {
                    dp[b] = -INF;
                }
            }
        }
    }
    let ans = if dp[N] == -INF {
        -1
    } else if dp[N] <= 0 {
        -dp[N]
    } else {
        0
    };

    println!("{}", ans);
}
