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
    let (a1, b1) = get!(usize, usize);
    let (a2, b2) = get!(usize, usize);
    let (a3, b3) = get!(usize, usize);

    // 次数3の頂点が存在するならばNO
    let mut dp = vec!(0; 5);
    dp[a1] += 1;
    dp[b1] += 1;
    dp[a2] += 1;
    dp[b2] += 1;
    dp[a3] += 1;
    dp[b3] += 1;
    let ans = if !dp.contains(&3) {
        "YES"
    } else {
        "NO"
    };

    println!("{}", ans);
}
