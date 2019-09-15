#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let s: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };
    let t: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    // 各アルファベットについて、sの出現位置をメモしておく
    // メモした出現位置用いた二分探索により、次のインデックスを計算する　
    let N = s.len();
    let mut x: std::collections::HashMap<_, _> = (0..26).map(|i| {
        let ascii_code = ('a' as u8) + i;
        (ascii_code as char, vec![])
    }).collect();
    for (i, &c) in s.iter().enumerate() { x.get_mut(&c).unwrap().push(i as i64); }
    for (i, &c) in s.iter().enumerate() { x.get_mut(&c).unwrap().push((i + N) as i64); }
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
    let k: i64 = t.iter().fold(-1, |res, &c| {
        if res == -2 || x[&c].is_empty() { -2 }
        else {
            let i = res % (N as i64);
            let j = bis(x[&c].len() as i64, -1, |j| x[&c][j as usize] > i);
            res + (x[&c][j as usize] - i)
        }
    });
    let ans = if k >= 0 { k + 1 } else { -1 };

    println!("{}", ans);
}
