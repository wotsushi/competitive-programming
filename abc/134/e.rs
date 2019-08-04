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
    let A = get!(i64; N);

    // 解は最長非増加部分列の長さ
    let mut dp: Vec<i64> = vec!(-1; N + 1);
    for a in A {
        let i = bis(N as i64, -1, |j| dp[j as usize] < a) as usize;
        dp[i] = a;
    }
    let ans = dp.into_iter().filter(|&x| x >= 0).count();

    println!("{}", ans);
}
