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
    let N = get!(i64);
    let a = get!(Vec<i64>);
    let b = get!(Vec<i64>);

    // k=0, 1, ..., について、bの各要素の下k桁の値をソートしておく
    let mut C = (0..30).map(
        |k| {
            let mut c = b.iter().map(|x|
                x & ((1 << k) - 1)
            ).collect::<Vec<_>>();
            c.sort();
            c
        }
    ).collect::<Vec<_>>();

    // a, bのk桁目同士の和と(k-1)桁目までの和に関する繰り上がりを求め、
    // 解のk桁目を求める
    let ans = (0..30).map(
        |k| (
            (
                (
                    if N % 2 == 0 {
                        0
                    } else {
                        a.iter()
                        .chain(b.iter())
                        .filter(|&x| x & (1 << k) > 0)
                        .count()
                    }
                    as i64
                ) +
                a.iter()
                    .map(
                        |x| {
                            let mut ok = N;
                            let mut ng = -1;
                            let m = (1 << k) - (x & ((1 << k) - 1));
                            while (ok - ng) > 1 {
                                let mid = (ok + ng) / 2;
                                if C[k][mid as usize] >= m {
                                    ok = mid;
                                } else {
                                    ng = mid;
                                }
                            }
                            N - ok
                        }
                    ).sum::<i64>()
            ) % 2
        ) << k
    ).sum::<i64>();

    println!("{}", ans);
}
