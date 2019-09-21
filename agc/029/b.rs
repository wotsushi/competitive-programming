#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    // 大きい値から順に貪欲にペアを作成する
    let B = {
        let mut B = A.clone();
        B.sort();
        B
    };
    let mut s = std::collections::HashMap::new();
    for &a in &A { *(s.entry(a).or_insert(0)) += 1; }
    for &b in B.iter().rev() {
        let k = format!("{:b}", b).len();
        let c = (1 << k) - b;
        if b == c && *s.get(&b).unwrap_or(&0) >= 2 { *(s.entry(b).or_insert(0)) -= 2; }
        if b != c && *s.get(&b).unwrap_or(&0) > 0 && *s.get(&c).unwrap_or(&0) > 0 {
            *(s.entry(b).or_insert(0)) -= 1;
            *(s.entry(c).or_insert(0)) -= 1;
        }
    }
    let ans = (N - s.values().sum::<usize>()) / 2;

    println!("{}", ans);
}