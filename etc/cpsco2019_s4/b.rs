#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, D): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let S: Vec<Vec<char>> = (0..D)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().chars().collect()
        })
        .collect();

    let ans = (0..(D - 1))
        .map(|i| ((i + 1)..D)
            .map(|j| {
                let mut mems = std::collections::HashSet::new();
                for k in 0..N { if S[i][k] == 'o' { mems.insert(k); } }
                for k in 0..N { if S[j][k] == 'o' { mems.insert(k); } }
                mems.len()
            })
            .max()
            .unwrap())
        .max()
        .unwrap();

    println!("{}", ans);
}
