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
    let (N, M) = get!(usize, usize);
    let (a, b): (Vec<i64>, Vec<i64>) = get!(i64, i64; N).into_iter().unzip();
    let (c, d): (Vec<i64>, Vec<i64>) = get!(i64, i64; M).into_iter().unzip();

    for (x, y) in a.iter().zip(b.iter()) {
        let ans = (0..M).min_by_key(|&i| (x - c[i]).abs() + (y - d[i]).abs()).unwrap() + 1;
        println!("{}", ans);
    }
}