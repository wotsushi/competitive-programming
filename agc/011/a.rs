#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, C, K): (usize, usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let T: Vec<usize> = (0..N)
        .map(|_| {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                line.trim().parse().unwrap()
        })
        .collect();

    let S = {
        let mut S = T.clone();
        S.sort();
        S
    };
    let (ans, _, _) = S[1..].iter().fold((1, S[0], 1), |(res, x, y), &t| {
        if t > x + K || y == C { (res + 1, t, 1) } else { (res, x, y + 1) }
    });

    println!("{}", ans);
}