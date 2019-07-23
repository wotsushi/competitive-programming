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

fn bis<F>(ok: i64, ng: i64, p: F) -> i64
    where F : Fn(i64) -> bool {

    let mid = (ok + ng) / 2;
    if (ok - ng).abs() == 1 {
        ok
    } else if p(mid) {
        bis(mid, ng, p)
    } else {
        bis(ok, mid, p)
    }
}

fn main() {
    let N = get!(usize);
    let mut A = get!(Vec<i64>);
    let mut B = get!(Vec<i64>);
    let mut C = get!(Vec<i64>);

    A.push(0);
    A.sort();
    B.sort();
    C.push(10_000_000_000);
    C.sort_by_key(|&c| -c);

    // 二分探索により、上に乗せられるパーツを求める
    let mut acc = 0;
    let ans = B.iter()
        .map(
            |&b|
            {
                bis(0, (N + 1) as i64, |k| { A[k as usize] < b }) *
                bis(0, (N + 1) as i64, |k| { C[k as usize] > b })
            }
        )
        .sum::<i64>();

    println!("{}", ans);
}
