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
    let A = get!(usize; N);

    // 最大値をとるインデックスkを一つ求める
    // A_i (i != k) を除く最大要素は A_k である
    // A_k を除く最大要素は素直に求めればよい
    let k = (0..N).max_by_key(|&i| A[i]).unwrap();

    for i in 0..N {
        let ans = if i == k {
            (0..N).map(
                |i|
                if i == k {
                    0
                } else {
                    A[i]
                }
            )
            .max()
            .unwrap()
        } else {
            A[k]
        };
        println!("{}", ans);
    }
}
