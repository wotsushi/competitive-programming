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

fn main() {
    let MOD = 1000000007;

    let (N, K) = get!(usize, usize);

    // i - 1 > N - K ならばちょうどi回する操作は存在しない
    // そうでなければ (K - 1)C(i - 1) * (N - K + 1)C(N - K - i + 1)
    let mut dp: Vec<Vec<i64>> = vec!(vec!(0; N + 1); N + 1);
    dp[0][0] = 1;
    for i in 1..(N + 1) {
        dp[i][0] = 1;
        for j in 1..(i + 1) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD
        }
    }
    for i in 1..(K + 1) {
        let ans = if i - 1 <= N - K {
            (dp[K - 1][i - 1] * dp[N - K + 1][N + 1 - K - i]) % MOD
        } else {
            0
        };
        println!("{}", ans);
    }
}