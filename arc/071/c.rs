#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let n: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let S: Vec<Vec<char>> = (0..n)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().chars().collect()
        })
        .collect();

    let ascii_lowercase = "abcdefghijklmnopqrstuvwxyz".chars().collect::<Vec<_>>();
    let mut res = vec![];
    for &c in &ascii_lowercase {
        for _ in 0..S
            .iter()
            .map(|s| s.iter().filter(|&&x| x == c).count())
            .min()
            .unwrap()
        {
            res.push(c);
        }
    }
    let ans = res
        .iter()
        .map(|&c| c.to_string())
        .collect::<Vec<_>>()
        .join("");

    println!("{}", ans);
}
