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
    let (N, K) = get!(usize, i32);
    let (A, B): (Vec<_>, Vec<_>) = get!(i32, usize; N).into_iter().unzip();

    // 桁DPにより解を求める
    let L = 30;
    let ans = (0..(L + 1)).map(
        |k|
        {
            (0..N).filter(
                |&i|
                {
                    let a = A[i];
                    let b = B[i];
                    (0..k).all(|i| ((a >> (L - i - 1)) & 1) <= ((K >> (L - i - 1)) & 1)) &&
                    (k == L || (a >> (L - k - 1) & 1) == 0) &&
                    (k == L || (K >> (L - k - 1) & 1) == 1)
                }
            )
            .map(|i| B[i])
            .sum::<usize>()
        }
    )
    .max()
    .unwrap();

    println!("{}", ans);
}
