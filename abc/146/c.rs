#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (A, B, X): (i64, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };

    fn bis<P: Fn(i64) -> bool>(ok: i64, ng: i64, p: P) -> i64 {
        let mid = (ok + ng) / 2;
        if (ok - ng).abs() == 1 {
            ok
        } else if p(mid) {
            bis(mid, ng, p)
        } else {
            bis(ok, mid, p)
        }
    }

    let ans = bis(0, 1e9 as i64 + 1, |N| {
        A * N + B * format!("{}", N).len() as i64 <= X
    });

    println!("{}", ans);
}
