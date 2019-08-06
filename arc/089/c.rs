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
    let mut txy = get!(i64, i64, i64; N);

    txy.insert(0, (0, 0, 0));
    // マンハッタン距離を求め、時間が間に合う、かつ、パリティが合うならば移動可能
    let ans = if (0..N).all(
        |i|
        {
            let (t1, x1, y1) = txy[i];
            let (t2, x2, y2) = txy[i + 1];
            let d = (x2 - x1).abs() + (y2 - y1).abs();
            let dt = t2 - t1;
            d <= dt && (dt - d) % 2 == 0
        }
    ) {
        "Yes"
    } else {
        "No"
    };

    println!("{}", ans);
}
