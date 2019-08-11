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

use std::collections::BinaryHeap;

fn main() {
    let (N, M) = get!(usize, usize);
    let mut AB = get!(usize, i64; N);

    // 後ろから（M-1日後から）貪欲に詰める
    AB.sort_by_key(|&(a, b)| (a, -b));
    let (A, B): (Vec<usize>, Vec<i64>) = AB.into_iter().unzip();
    let mut i = 0;
    let mut q = BinaryHeap::new();
    let mut ans = 0;
    for k in 1..(M + 1) {
        while i < N && A[i] <= k {
            q.push(B[i]);
            i += 1;
        }
        ans += match q.pop() {
            Some(b) => b,
            _ => 0
        }
    }

    println!("{}", ans);
}

