#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let L: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    const INF: i64 = 1_000_000_000;
    let S = {
        let mut S = L.clone();
        S.push(INF);
        S.sort();
        S
    };
    let ans = (0..(N - 2)).map(|i| {
        let (s, _) = ((i + 1)..(N - 1)).fold((0, i + 2), |(res, k), j| {
            let r = (k..(N + 1)).find(|&l| S[l] >= S[i] + S[j]).unwrap();
            (res + r - j - 1, r)
        });
        s
    }).sum::<usize>();

    println!("{}", ans);
}