macro_rules! get {
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
    ($t:ty ;;) => {
        {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.split_whitespace()
                .map(|t| t.parse::<$t>().unwrap())
                .collect::<Vec<_>>()
        }
    };
    ($t:ty ;; $n:expr) => {
        (0..$n).map(|_| get!($t ;;)).collect::<Vec<_>>()
    };
}

fn main() {
    let (N, K) = get!(usize, usize);
    let MOD: usize = 1000000007;

    // floor(N / i) の値に応じてグループ分けし、
    // グループ単位で条件を満たす列の個数を動的計画法で求める
    let P = (N as f64).sqrt() as usize;
    let Q = N / P;
    let R = P + Q;
    let C = (0..R).map(|i|
        if i <= P {
            1
        } else {
            N / (R - i) - N / (R - i + 1)
        }
    ).collect::<Vec<_>>();
    let mut dp = vec![vec![0; R]; K];
    for i in 0..R {
        dp[0][i] = C[i];
    }
    for j in 1..K {
        let mut acc = 0;
        for i in (1..R).rev() {
            acc = (acc + dp[j - 1][R - i]) % MOD;
            dp[j][i] = (C[i] * acc) % MOD;
        }
    }
    let ans: usize = dp[K - 1].iter().sum::<usize>() % MOD;

    println!("{}", ans);
}
