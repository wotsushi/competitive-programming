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
use std::collections::HashSet;

fn main() {
    let (N, Q) = get!(usize, usize);
    let STX = get!(i64, i64, i64; N);
    let D = get!(i64; Q);

    let INF: i64 = 1000000000000000;

    // 各時間帯について、その時間帯に出発すると影響を受ける工事を前もって求める
    // 前もって求めた時間帯→工事を用いて、各クエリに回答する
    let mut C = vec!();
    for (s, t, x) in STX {
        C.push((s - x, x, 1));
        C.push((t - x, x, 0));
    }
    C.sort();
    let mut q = BinaryHeap::new();
    let mut R = HashSet::new();
    let mut u = Vec::new();
    let mut v = Vec::new();
    q.push(-INF);
    for (t, x, k) in C {
        let p = -q.peek().unwrap();
        if k == 1 {
            if x < p {
                u.push(t);
                v.push(p);
            }
            if R.contains(&x) {
                R.remove(&x);
            } else {
                q.push(-x);
            }
        } else {
            R.insert(x);
            if x == p {
                u.push(t);
                v.push(p);
            }
            while R.contains(&-q.peek().unwrap()) {
                R.remove(&-q.pop().unwrap());
            }
        }
    }
    u.push(INF);
    v.push(INF);
    let mut Y = Vec::new();
    let mut i = 0;
    for d in D {
        while u[i] <= d {
            i += 1;
        }
        Y.push(v[i]);
    }

    for y in Y {
        if y == INF {
            println!("-1");
        } else {
            println!("{}", y)
        }
    }
}
