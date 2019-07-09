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
    let (A, B, C, D, E, F) = get!(usize, usize, usize, usize, usize, usize);

    // 全探索により解を求める
    let mut ans = (100 * A, 0);
    for a in (0..(F / (100 * A) + 1)).map(|a| 100 * A * a) {
        for b in (0..((F - a) / (100 * B) + 1)).map(|b| 100 * B * b) {
            for c in (0..((F - a - b) / C + 1)).map(|c| C * c) {
                for d in (0..((F - a - b - c) / D + 1)).map(|d| D * d) {
                    let (u, v) = ans;
                    let (x, y) = (a + b + c + d, c + d);
                    if c + d <= E * (a + b) / 100 && u * y > v * x {
                        ans = (x, y);
                    }
                }
            }
        }
    }

    println!("{} {}", ans.0, ans.1);
}
