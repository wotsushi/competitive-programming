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
    let N = get!(usize);
    let a = get!(Vec<usize>);

    // 必ず構築可能
    // 末尾から定めればよい
    let mut dp = vec!(0; N);
    for i in (1..(N + 1)).rev() {
        dp[i - 1] = (
            (1..(N / i))
                .map(|j| dp[(j + 1) * i - 1])
                .sum::<usize>()
            + a[i - 1]
        ) % 2;
    }
    let M = dp.iter().sum::<usize>();
    let b = (0..N)
        .filter(|&i| dp[i] == 1)
        .map(|i| (i + 1).to_string())
        .collect::<Vec<_>>()
        .join(" ");
    let ans = if M == 0 {
        format!("{}", M)
    } else {
        format!("{}\n{}", M, b)
    };

    println!("{}", ans);
}
