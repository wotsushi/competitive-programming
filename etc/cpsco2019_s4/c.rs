#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, D): (usize, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let R: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let Rg = {
        let mut Rg = R.clone();
        Rg.sort();
        Rg.push(3_000_000_000);
        Rg
    };
    let (ans, _) = (0..(N - 2))
        .fold((0, 2), |(res, l), i| {
            let r = (l..(N + 1)).find(|&j| Rg[j] - Rg[i] > D).unwrap();
            let n = r - i - 1;
            (res + n * (n - 1) / 2, r)
        });

    println!("{}", ans);
}
