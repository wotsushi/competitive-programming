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
    let (N, D) = get!(usize, usize);
    let mut X = Vec::new();
    for _ in 0..N {
        X.push(get!(Vec<i32>));
    }

    let mut ans = 0;
    for i in (0..(N - 1)) {
        for j in ((i + 1)..N) {
            let s = X[i].iter().zip(X[j].iter())
                .map(|(y, z)| (y - z).pow(2))
                .sum::<i32>();
            ans += match (1..1000).find(|r| r * r == s) {
                Some(_) => 1,
                _ => 0
            }
        }
    }

    println!("{}", ans);
}
