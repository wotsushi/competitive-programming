#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let C: Vec<Vec<char>> = (0..H).map(|_| {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    }).collect();

    let ans = (0..(2 * H))
        .map(|i| C[i / 2].iter().map(|&c| c).collect::<String>())
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}