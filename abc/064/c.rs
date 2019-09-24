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

    let fixed_cnt = A.iter()
        .map(|&a| a / 400)
        .filter(|&a| a < 8)
        .collect::<std::collections::HashSet<_>>()
        .len();
    let free_cnt = A.iter()
        .filter(|&&a| a >= 3200)
        .count();
    let ans = format!(
        "{} {}",
        std::cmp::max(1, fixed_cnt),
        fixed_cnt + free_cnt
    );

    println!("{}", ans);
}
