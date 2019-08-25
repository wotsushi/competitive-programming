#![allow(non_snake_case)]
#![allow(unused_variables)]

fn bis<P>(ok: i64, ng: i64, p: P) -> i64
    where P: Fn(i64) -> bool {
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
    let Q: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (A, B): (Vec<i64>, Vec<i64>) = {
        let (mut A, mut B) = (vec![], vec![]);
        for _ in 0..Q {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            A.push(iter.next().unwrap().parse().unwrap());
            B.push(iter.next().unwrap().parse().unwrap());
        }
        (A, B)
    };

    // 高橋君よりスコアの小さい参加者は、どちらかのコンテストでsqrt(ab)より小さい
    // 順位をとっていることを利用して数え上げる
    let ans = (0..Q).map(
        |i|
        {
            let a = std::cmp::min(A[i], B[i]);
            let b = std::cmp::max(A[i], B[i]);
            let s = bis(0, b + 1, |k| k * k < a * b);
            let res = if a == b {
                2 * (a - 1)
            } else if s * (s + 1) >= a * b {
                2 * (s - 1)
            } else {
                2 * (s - 1) + 1
            };
            res.to_string()
        }
    )
    .collect::<Vec<_>>()
    .join("\n");

    println!("{}", ans);
}
