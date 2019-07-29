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
    let S = get!(String).chars().collect::<Vec<_>>();

    // 末尾文字から順に13で割った余りについてDPで解を求める
    let M = 13;
    let MOD = 1000000007;
    let (dp, _) = S.iter()
        .rev()
        .map(|c| c.to_digit(10))
        .fold(
            (
                (0..M).map(
                    |i| match i {
                        0 => 1,
                        _ => 0
                    }
                ).collect::<Vec<_>>(),
                1
            ),
            |(dp, acc), c| {
                (
                    match c {
                        None => (0..M)
                            .map(
                                |i|
                                (0..10).map(|j| dp[(M * M + i - j * acc) % M])
                                    .sum::<usize>() % MOD
                            )
                            .collect::<Vec<_>>(),
                        Some(k) => (0..M)
                            .map(|i| dp[(M * M + i - (k as usize) * acc) % M])
                            .collect::<Vec<_>>()
                    },
                    (10 * acc) % M
                )
            }
        );
    let ans = dp[5];

    println!("{}", ans);
}
