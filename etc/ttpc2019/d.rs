#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let X: Vec<usize> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    // 各山のGrundy数を求めてどちらが必勝か判定する
    let M = *X.iter().max().unwrap();
    let p = {
        let mut p = vec![true; M + 1];
        p[0] = false;
        p[1] = false;
        for i in 2..(M + 1) { if p[i] { for j in 2..(M / i + 1) { p[j * i] = false; } } }
        p
    };
    let g = X.iter()
        .map(|&x| if x == 7 { 3 } else if p[x - 2] { 2 } else { 1 })
        .fold(0, |acc, x| acc ^ x);
    let ans = if g > 0 { "An" } else { "Ai" };

    println!("{}", ans);
}
