#![allow(non_snake_case)]
#![allow(unused_variables)]

fn iceil(x: i64, y: i64) -> i64 {
    (x + y - 1) / y
}

fn f(b: i64, n: i64) -> i64 {
    if n < b {
        n
    } else {
        f(b, n / b) + n % b
    }
}

fn bis<P>(ok: i64, ng: i64, p: P) -> i64
    where P : Fn(i64) -> bool {
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
    let n: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let s: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    // 2以上sqrt(n)以下で該当するbがあればそれが解
    // そうでなければnをb進表記すると2桁なので、上位桁について全探索すればよい
    let ans = if s > n || (iceil(n, 2) < s && s < n) {
        -1
    } else if s == n {
        n + 1
    } else {
        let sqn = bis(1_000_000_000, 0, |x| x * x > n);
        let b = (2..sqn).find(|&i| f(i, n) == s);
        match b {
            Some(c) => c,
            None => {
                let j = (1..sqn).rev().find(|&i| (f((n - s + i) / i, n) == s)).unwrap();
                (n - s + j) / j
            }
        }
    };

    println!("{}", ans);
}
